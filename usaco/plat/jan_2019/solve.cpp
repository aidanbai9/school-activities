#include "bits/extc++.h"

using namespace std;

using ll = long long;

#define sz(x) int(std::size(x))

void solve(){
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    int dp[n+1]{};
    for(auto &u: dp) u=1e9;
    dp[n]=0;
    vector<int>wet(n);
    for(int i = 0; i<n; i++){
        if(s[i]=='H') wet[i]=1;
        else wet[i]=-1;
    }
    int ssum[n+1]{};
    auto rsum = [&](int l, int r) -> int {
        return ssum[l]-ssum[r+1];
    };
    for(int i = n-1; i>=0; i--){
        if(s[i]=='H') ssum[i]=ssum[i+1]+1;
        else ssum[i]=ssum[i+1]-1;
    }
    for(int i = n-1; i>=0; i--){
        int sum=0;
        bool vis1=0,vis2=0;
        for(int j = min(k-1,n-1-i); j>=0; j--){
            sum=rsum(i,i+j);
            if(sum>0 && !vis1){
                cout<<i<<" "<<i+j+1<<" trs\n";
                dp[i]=min(dp[i],dp[i+j+1]);
                vis1=1;
            }else if(!vis2 && sum<=0){
                cout<<i<<" "<<i+j+1<<" trs2\n";
                dp[i]=min(dp[i],dp[i+j+1]+1);
                vis2=1;
            }
            if(vis1 && vis2) break;
        }
    }
    cout<<dp[0]<<"\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(ios::failbit);
#ifndef LOCAL
    freopen("redistricting.in","r",stdin);
    freopen("redistricting.out","w",stdout);
#endif
    solve();
}