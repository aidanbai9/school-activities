#include "bits/extc++.h"

using namespace std;

using ll = long long;

#define sz(x) int(std::size(x))

constexpr int maxn = 1e5+5;

int dp[maxn];
int sufm[maxn];

int init(vector<int>arr){
    int n=sz(arr);
    for(int i = 0; i<n; i++) dp[i+1]=arr[i];
    dp[0]=0;
    sufm[n]=0;
    for(int i = n-1; i>=0; i--){
        dp[i]+=min(dp[i+1],sufm[i+1]);
        sufm[i]=max(sufm[i+1],dp[i+1]);
    }
    return dp[0];
}

void solve(){
    int n,q;
    cin>>n>>q;
    vector<int>arr(n);
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    cout<<init(arr)<<"\n";
    while(q--){
        int idx,val;
        cin>>idx>>val;
        arr[idx]=val;
        cout<<init(arr)<<"\n";
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(ios::failbit);
    solve();
}