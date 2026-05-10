#include "bits/extc++.h"

using namespace std;

using ll = long long;

#define sz(x) int(std::size(x))

#include <stdio.h>
#include <stdlib.h>

#define fail(s, x...) do { \
		fprintf(stderr, s "\n", ## x); \
		exit(1); \
	} while(0)

#define MAX_SIZE 1000000000
#define MAX_N 100000

long long gcd2(long long X, long long Y) {
    long long tmp;
    while (X != Y && Y != 0) {
        tmp = X;
        X = Y;
        Y = tmp % Y;
    }
    return X;
}

constexpr int maxn = 105;

vector<vector<ll>>vals(maxn,vector<ll>(maxn,0));

void init(int R, int C) {
    /* ... */
}

void update(int P, int Q, long long K) {
    vals[P][Q]=K;
}

long long calculate(int P, int Q, int U, int V) {
    ll gcdv=0;
    for(int i = P; i<=U; i++){
        for(int j = Q; j<=V; j++){
            gcdv=gcd(gcdv,vals[i][j]);
        }
    }
    return gcdv;
}


int main() {
	int R, C, N;
    int P, Q, U, V;
    long long K;
    int i, type;
	int res;

	FILE *f = fopen("game.in", "r");
	if (!f)
		fail("Failed to open input file.");

	res = fscanf(f, "%d", &R);
	if (res != 1)
		fail("Failed to read R from input file.");
	if (R < 1 || R > MAX_SIZE)
		fail("R is out of bounds.");

	res = fscanf(f, "%d", &C);
	if (res != 1)
		fail("Failed to read C from input file.");
	if (C < 1 || C > MAX_SIZE)
		fail("C is out of bounds.");

	res = fscanf(f, "%d", &N);
	if (res != 1)
		fail("Failed to read N from input file.");
	if (N < 0 || N > MAX_N)
		fail("N is out of bounds.");

    init(R, C);

	for (i = 0; i < N; i++) {
        res = fscanf(f, "%d", &type);
        if (type == 1) {
		    res = fscanf(f, "%d%d%lld", &P, &Q, &K);
            update(P, Q, K);
        } else if (type == 2) {
		    res = fscanf(f, "%d%d%d%d", &P, &Q, &U, &V);
            printf("%lld\n", calculate(P, Q, U, V));
        } else
			fail("Invalid action type in input file.");
	}
	fclose(f);

	return 0;
}
