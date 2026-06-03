#!/usr/bin/env python3

"""
Example usage:

First create an input file, like "census.input0.txt" with the following contents:
N M
ID_0 ID_1 ID_2 ... ID_{N-1}

For example:
2 100
0 3

For python programs, say "census.py" (normally run as "pypy3 census.py"):

    python3 testing_tool.py pypy3 census.py < census.input0.txt

For C++ programs, first compile it
(e.g. with "g++ -g -O2 -std=gnu++20 census.cpp")
and then run

    python3 testing_tool.py ./a.out < census.input0.txt

Your program can write debugging prints to stderr. They will be reported by the testing tool,
but possibly out of sync with the issued queries.

"""

from collections import Counter, defaultdict
from dataclasses import dataclass
from fcntl import fcntl
from io import BufferedReader, BufferedWriter
import os
import select
import signal
import sys
import time
from typing import List, NoReturn, Optional

PRINT_CAP = 60
QWIDTH = 10
QPERLINE = 10

MAX_LOCATION = 10**18 - 1
MAX_WRITE = 10**9
MAX_DAYS = 500


def error(msg: str) -> NoReturn:
    print("ERROR:", msg, file=sys.stderr)
    sys.exit(1)

def parse_int(s: str, what: str, lo: int, hi: Optional[int]) -> int:
    try:
        ret = int(s)
    except Exception:
        error(f"Failed to parse {what} as integer: {s}")
    if hi is None:
        if ret < lo:
            error(f"{what} out of bounds: {ret} < {lo}")
    elif not (lo <= ret <= hi):
        error(f"{what} out of bounds: {ret} not in [{lo}, {hi}]")
    return ret

def crop(s: str, w: int) -> str:
    if len(s) > w:
        return s[:w-1] + "…"
    return s

def wait_for_child(pid: int) -> None:
    pid, status = os.waitpid(pid, 0)
    if os.WIFSIGNALED(status):
        sig = os.WTERMSIG(status)
        error(f"Program terminated with signal {sig} ({signal.Signals(sig).name})")
    ex = os.WEXITSTATUS(status)
    if ex != 0:
        error(f"Program terminated with exit code {ex}")


@dataclass
class Proc:
    i: int
    id: int
    pid: Optional[int]
    stdout_buf: bytes
    stderr_buf: bytes
    poll: select.poll
    poll_stderr: select.poll
    stdout_fd: int
    stdout_eof: bool
    stdout_reader: BufferedReader
    stderr_reader: BufferedReader
    stdin_writer: BufferedWriter

    def print_stderr(self, line: bytes) -> None:
        decoded = line.decode("latin1")
        if "\033[" in decoded:
            # Reset colors (ASAN otherwise continues colored output onto
            # the following "Instance I stderr:" prompt)
            decoded += "\033[0m"
        print(f"Instance {self.i} (with ID = {self.id}) stderr: {decoded}")

    def read_stderr(self, *, known_readable: bool, final: bool) -> None:
        data = []
        while True:
            if not known_readable:
                # Check using poll (2) whether it's fine to read from the
                # stderr pipe, or if it will block. CPython has false
                # positives here around EINTR, but that should never come
                # up on Linux at least.
                if not self.poll_stderr.poll(0):
                    break
            r = self.stderr_reader.read1()
            if not r:
                break
            data.append(r)
            known_readable = False
        if not data and not final:
            return
        self.stderr_buf += b"".join(data)
        lines = self.stderr_buf.split(b"\n")
        for line in lines[:-1]:
            self.print_stderr(line)
        self.stderr_buf = lines[-1]
        if final and self.stderr_buf:
            # Partial line
            self.print_stderr(self.stderr_buf)
            self.stderr_buf = b""

    def read_line(self) -> Optional[str]:
        assert self.pid is not None
        while b"\n" not in self.stdout_buf and not self.stdout_eof:
            # Read stdout/stderr in parallel until stdout contains a newline.
            for fd, _ in self.poll.poll():
                if fd == self.stdout_fd:
                    r = self.stdout_reader.read1()
                    if not r:
                        self.stdout_eof = True
                    self.stdout_buf += r
                else:
                    self.read_stderr(known_readable=True, final=False)
        ind = self.stdout_buf.find(b"\n")
        if ind == -1:
            ind = len(self.stdout_buf)
        else:
            ind += 1
        line = self.stdout_buf[:ind]
        self.stdout_buf = self.stdout_buf[ind:]
        if not line:
            pid = self.pid
            self.pid = None
            self.read_stderr(known_readable=False, final=True)
            wait_for_child(pid)
            return None
        else:
            self.read_stderr(known_readable=False, final=False)
        return line.decode("latin1").rstrip("\r\n")

    def write_line(self, line: str) -> None:
        try:
            self.stdin_writer.write((line + "\n").encode("ascii"))
            self.stdin_writer.flush()
        except BrokenPipeError:
            pass


def start_submission(submission: List[str], i: int, id: int) -> Proc:
    stdout_read, stdout_write = os.pipe()
    stderr_read, stderr_write = os.pipe()
    stdin_read, stdin_write = os.pipe()

    sys.stdout.flush()
    sys.stderr.flush()

    pid = os.fork()

    if pid == 0:
        if sys.stderr.isatty() and "ASAN_OPTIONS" not in os.environ:
            os.environ["ASAN_OPTIONS"] = "color=always"

        os.close(stdin_write)
        os.close(stdout_read)
        os.close(stderr_read)

        os.dup2(stdin_read, 0)
        os.dup2(stdout_write, 1)
        os.dup2(stderr_write, 2)

        try:
            os.execvp(submission[0], submission)
        except Exception as e:
            error(f"Failed to execute program: {e}")
        assert False, "unreachable"
    else:
        os.close(stdout_write)
        os.close(stderr_write)
        os.close(stdin_read)
        stdout_reader = os.fdopen(stdout_read, "rb")
        stderr_reader = os.fdopen(stderr_read, "rb")
        stdin_writer = os.fdopen(stdin_write, "wb")
        poll = select.poll()
        poll.register(stdout_read, select.POLLIN)
        poll.register(stderr_read, select.POLLIN)
        poll_stderr = select.poll()
        poll_stderr.register(stderr_read, select.POLLIN)
        return Proc(i, id, pid, b"", b"", poll, poll_stderr,
                    stdout_read, False, stdout_reader, stderr_reader, stdin_writer)


def main() -> None:
    silent = False
    args = sys.argv[1:]
    if args and args[0] == "--silent":
        args = args[1:]
        silent = True
    if not args:
        print("Usage:", sys.argv[0], "[--silent] program... <input.txt")
        sys.exit(0)

    nk = input().split()
    if len(nk) != 2:
        error(f"First line must contain two values: N and M")
    n = parse_int(nk[0], "N", 1, None)
    m = parse_int(nk[1], "M", 1, None)
    sids = input().split()
    if len(sids) != n:
        error(f"Second line must contain N = {n} values, but found {len(sids)}")
    ids = [parse_int(x, "ID", 0, m-1) for x in sids]

    what, occ = Counter(ids).most_common(1)[0]
    if occ != 1:
        error(f"Second line must not contain any duplicates, but {what} occurs {occ} times")

    marked_locations = dict()

    print(f"[*] Starting run with N = {n}, M = {m}")
    processes = []
    num_days = 0
    try:
        for i, id in enumerate(ids):
            proc = start_submission(args, i, id)
            processes.append(proc)
            proc.write_line(f"{id} {m}")

        while any(proc.pid is not None for proc in processes):
            reads = []
            writes = defaultdict(list)
            lines: List[Optional[str]] = []
            answers = []

            num_days += 1
            if num_days > MAX_DAYS:
                error(f"Used more than {MAX_DAYS} days before answering")

            if not silent:
                print(f"[*] Day {num_days}")

            for i in range(n):
                proc = processes[i]
                if proc.pid is None:
                    lines.append(None)
                    continue
                line = proc.read_line()
                if line is None:
                    error(f"Instance {i} (with ID = {ids[i]}) exited without having printed an answer")
                lines.append(line.strip())

            outlines = []
            for i in range(n):
                line = lines[i]
                if line is None:
                    outlines.append("")
                    continue

                toks = line.split()
                if not toks or toks[0] not in ("r", "w", "!"):
                    error(f"Unexpected output: expected query of type \'r\', \'w\' or \'!\', found: {line}")
                c = toks[0]
                if c == "w":
                    if len(toks) != 3:
                        error(f"Bad query: {line}")
                    loc = parse_int(toks[1], "location", 0, MAX_LOCATION)
                    val = parse_int(toks[2], "write value", 0, MAX_WRITE)
                    writes[loc].append((i, val))
                    outlines.append(line)
                elif c == "r":
                    if len(toks) != 2:
                        error(f"Bad query: {line}")
                    loc = parse_int(toks[1], "location", 0, MAX_LOCATION)
                    reads.append((i, loc))
                    outlines.append(line)
                else:
                    if len(toks) != 2:
                        error(f"Bad query: {line}")
                    ans = parse_int(toks[1], "answer", 0, None)
                    answers.append((i, ans))
                    outlines.append(line)

            for loc, vals in writes.items():
                if len(vals) > 1:
                    who = [i for i, _ in vals]
                    print(f"[*] Wrong Answer: multiple writes to location {loc} (from instances {who}, with IDs: {[ids[i] for i in who]})")
                    sys.exit(1)

            for (i, loc) in reads:
                processes[i].write_line(str(marked_locations[loc]) if loc in marked_locations else "0")
            for loc, vals in writes.items():
                val = vals[0][1]
                marked_locations[loc] = val
            if not silent:
                print(f"[*] Queries:")
                hdrw = len(str(n - 1)) + 1
                if n > QPERLINE:
                    hdr = " " * (hdrw + 1) if n > QPERLINE else ""
                    hdr2 = " ".join(str(i).ljust(QWIDTH) 
                                for i in range(min(QPERLINE, n)))
                    print(hdr + hdr2)
                    print(" " * len(hdr) + "=" * len(hdr2))
                for i in range(0, n, QPERLINE):
                    hdr = (str(i) + ":").rjust(hdrw) + " " if n > QPERLINE else ""
                    hdr = hdr.replace("0:", "_:")
                    print(hdr +
                          " ".join(crop(l, QWIDTH).ljust(QWIDTH) 
                                   for l in outlines[i : i + QPERLINE]))
                memstr = " ".join((str(marked_locations[i]) if i in marked_locations else "0") for i in range(PRINT_CAP)) + "..."
                print(f"[*] State = {memstr}")
                print()
            for (i, ans) in answers:
                if ans != n:
                    print(f"[*] Wrong Answer: instance {i} (with ID = {ids[i]}) guessed {ans}, but N = {n}")
                    sys.exit(1)
            for (i, ans) in answers:
                proc = processes[i]
                line = proc.read_line()
                if line is not None:
                    error(f"Instance {i} (with ID = {ids[i]}) printed another line after !: {line}")

    except:
        for proc in processes:
            if proc.pid is not None:
                os.kill(proc.pid, 9)
                os.waitpid(proc.pid, 0)
        raise

    print(f"[*] OK: used {num_days} days")

if __name__ == "__main__":
    main()
