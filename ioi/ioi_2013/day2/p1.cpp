#include "bits/extc++.h"

using namespace std;

using ll = long long;

#define sz(x) int(std::size(x))

#define MAX_N 5000
#define MAX_CALLS 70000

#define fail(s, x...) do { \
		fprintf(stderr, s "\n", ## x); \
		exit(1); \
	} while(0)

/* Symbol obfuscation */
#define N koala
#define realS kangaroo
#define realD possum
#define inv platypus
#define num_calls echidna

static int N;
static int realS[MAX_N];
static int realD[MAX_N];
static int inv[MAX_N];
static int num_calls;

void answer(int S[], int D[]) {
    int i;
    int correct = 1;
    for (i = 0; i < N; ++i)
        if (S[i] != realS[i] || D[i] != realD[i]) {
            correct = 0;
            break;
        }

    if (correct)
        printf("CORRECT\n");
    else
        printf("INCORRECT\n");

    for (i = 0; i < N; ++i) {
        if (i > 0)
            printf(" ");
        printf("%d", S[i]);
    }
    printf("\n");

    for (i = 0; i < N; ++i) {
        if (i > 0)
            printf(" ");
        printf("%d", D[i]);
    }
    printf("\n");

    exit(0);
}

int tryCombination(int S[]) {
    int i;

    if (num_calls >= MAX_CALLS) {
        printf("INCORRECT\nToo many calls to tryCombination().\n");
        exit(0);
    }
    ++num_calls;

    for (i = 0; i < N; ++i)
        if (S[inv[i]] != realS[inv[i]])
            return i;
    return -1;
}

int init() {
    int i, res;

    FILE *f = fopen("cave.in", "r");
	if (!f)
		fail("Failed to open input file.");

	res = fscanf(f, "%d", &N);

    for (i = 0; i < N; ++i) {
        res = fscanf(f, "%d", &realS[i]);
    }
    for (i = 0; i < N; ++i) {
        res = fscanf(f, "%d", &realD[i]);
        inv[realD[i]] = i;
    }

    num_calls = 0;
    return N;
}

vector<int>curans;
int n;

pair<int,int> nextd(set<int>&rem, int i){
    vector<int>vals;
    for(auto u: rem) vals.push_back(u);
    int tryv[n];
    for(int i = 0; i<n; i++) tryv[i]=curans[i];
    for(auto u: vals) tryv[u]=0;
    bool val=1;
    int valv=tryCombination(tryv);
    if(valv>i || valv==-1) val=0;
    auto check = [&](int x) -> bool {
        for(int i = 0; i<sz(vals); i++){
            if(i<=x){
                tryv[vals[i]]=val;
            }else{
                tryv[vals[i]]=!val;
            }
        }
        valv=tryCombination(tryv);
        return (valv>i || valv==-1);
    };
    int l=-1,r=sz(rem)-1;
    while(l<r-1){
        int mid = (l+r)/2;
        if(check(mid)){
            r=mid;
        }else{
            l=mid;
        }
    }
    return {vals[r],val};
}

void exploreCave(int N) {
    set<int>rem;
    int ans1[N],ans2[N];
    n=N;
    curans=vector<int>(N,0);
    for(int i = 0; i<N; i++) rem.insert(i);
    for(int i = 0; i<N; i++){
        pair<int,int>vals=nextd(rem,i);
        rem.erase(vals.first);
        curans[vals.first]=vals.second;
        ans2[vals.first]=i;
    }
    for(int i = 0; i<n; i++){
        ans1[i]=curans[i];
    }
    answer(ans1,ans2);
}

int main() {
    int N;
	N = init();
	exploreCave(N);
    printf("INCORRECT\nYour solution did not call answer().\n");
	return 0;
}