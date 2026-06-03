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

#define MAX_A 50000
#define MAX_B 50000
#define MAX_T 1000000

int an,bn,n;

template <typename T>
using min_pq = priority_queue<T,vector<T>,std::greater<T>>;

int oned(vector<int>&vals, vector<int>arr){
    sort(vals.begin(),vals.end());
    sort(arr.begin(),arr.end());
    int num=0,cnt=0;
    for(int i = sz(vals)-1; i>=0; i--){
        while(sz(arr) && arr.back()>=vals[i]){
            arr.pop_back();
            num++;
        }
        if(num==0) return -1;
        if(sz(vals)-i>ll(cnt)*num) cnt++;
    }
    if(sz(vals)==0) return 0;
    return cnt;
}

bool on(int i, int j){
    return i&(1<<j);
}

int putaway(int A, int B, int T, int X[], int Y[], int W[], int S[]) {
    an=A,bn=B,n=T;
    for(int i = 0; i<an; i++) X[i]--;
    for(int i = 0; i<bn; i++) Y[i]--;
    vector<int>arr,brr;
    vector<pair<int,int>>vals;
    for(int i = 0; i<n; i++) vals.push_back({W[i],S[i]});
    for(int i = 0; i<an; i++) arr.push_back(X[i]);
    sort(arr.begin(),arr.end());
    for(int i = 0; i<bn; i++) brr.push_back(Y[i]);
    sort(brr.begin(),brr.end());
    {
        for(int i = 0; i<n; i++){
            if((sz(arr)==0 || W[i]>arr.back()) && (sz(brr)==0 || S[i]>brr.back())) return -1;
        }
    }
    int minans=1e9;
    for(int i = 0; i<(1<<T); i++){
        vector<int>narr,nbrr;
        for(int j = 0; j<T; j++){
            if(on(i,j)){
                narr.push_back(W[j]);
            }else{
                nbrr.push_back(S[j]);
            }
        }
        int aans=oned(narr,arr),bans=oned(nbrr,brr);
        if(aans==-1 || bans==-1) continue;
        minans=min(minans,max(aans,bans));
    }
    return minans;
}
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               
static int X[MAX_A];
static int Y[MAX_B];
static int W[MAX_T];
static int S[MAX_T];

int main() {
    int A, B, T, i;
	int res;

	FILE *f = fopen("robots.in", "r");
	if (!f)
		fail("Failed to open input file.");

	res = fscanf(f, "%d", &A);
	if (res != 1)
		fail("Failed to read A from input file.");
	if (A < 0 || A > MAX_A)
		fail("A is out of bounds.");

	res = fscanf(f, "%d", &B);
	if (res != 1)
		fail("Failed to read B from input file.");
	if (B < 0 || B > MAX_B)
		fail("B is out of bounds.");

	res = fscanf(f, "%d", &T);
	if (res != 1)
		fail("Failed to read T from input file.");
	if (T < 1 || T > MAX_T)
		fail("T is out of bounds.");

	for (i = 0; i < A; i++) {
		res = fscanf(f, "%d", &X[i]);
		if (res != 1)
		    fail("Failed to read data from input file.");
    }
	for (i = 0; i < B; i++) {
        res = fscanf(f, "%d", &Y[i]);
        if (res != 1)
            fail("Failed to read data from input file.");
    }
	for (i = 0; i < T; i++) {
        res = fscanf(f, "%d%d", &W[i], &S[i]);
        if (res != 2)
            fail("Failed to read data from input file.");
    }
	fclose(f);

	int answer = putaway(A, B, T, X, Y, W, S);

	printf("%d\n", answer);

	return 0;
}
