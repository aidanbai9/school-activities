#include <bits/stdc++.h>

using namespace std;

int read(long long P) {
    int r;
    cout << "r " << P << endl;
    cin >> r;
    return r;
}

void write(long long P, int V) {
    cout << "w " << P << " " << V << endl;
}

int main() {
    int I, M;
    cin >> I >> M;

    write(I, 1);
    int x = read(I+1);

    int guess = 1;
    cout << "! " << guess << endl;

    return 0;
}
