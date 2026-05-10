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

int oned(vector<int>&vals, vector<int>arr){
    sort(vals.begin(),vals.end());
    sort(arr.begin(),arr.end());
    set<pair<int,int>>s;
    for(int i = sz(vals)-1; i>=0; i--){
        while(sz(arr) && arr.back()>=vals[i]){
            arr.pop_back();
            s.insert({0,sz(arr)});
        }
        if(sz(s)==0) return -1;
        auto it = s.begin();
        auto [val,idx] = (*it);
        s.erase(it);
        s.insert({val+1,idx});
    }
    if(sz(vals)==0) return 0;
    auto it = --s.end();
    return (*it).first;
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
    sort(vals.begin(),vals.end());
    if(an==0){
        vector<int>valb;
        for(auto [a,b]: vals) valb.push_back(b);
        return oned(valb,brr);
    }
    if(bn==0){
        vector<int>vala;
        for(auto [a,b]: vals) vala.push_back(a);
        return oned(vala,arr);
    }
    auto check = [&](int x) -> bool {
        set<pair<int,int>>s;
        vector<int>nbrr;
        set<pair<int,int>>cand;
        vector<int>crr=arr;
        for(int i = sz(vals)-1; i>=0; i--){
            while(sz(crr) && crr.back()>=vals[i].first){
                crr.pop_back();
                s.insert({0,sz(crr)});
            }
            if(sz(s)==0){
                nbrr.push_back(vals[i].second);
                continue;
            }
            auto it = s.begin();
            auto [val,idx] = (*it);
            if(val>=x){
                it = cand.begin();
                nbrr.push_back((*it).first);
                cand.erase(it);
                cand.insert({vals[i].second,vals[i].first});
            }else{
                s.erase(it);
                cand.insert({vals[i].second,vals[i].first});
                s.insert({val+1,idx});
            }
        }
        int ansv=oned(nbrr,brr);
        if(ansv==-1) return 0;
        return ansv<=x;
    };

    int l=0, r=T;
    while(l<r-1){
        int mid = (l+r)/2;
        if(check(mid)){
            r=mid;
        }else{
            l=mid;
        }
    }
    return r;
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
