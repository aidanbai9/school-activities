#include "bits/extc++.h"

using namespace std;

using ll = long long;

#define sz(x) int(std::size(x))

void solve(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i = 0; i<n; i++) cin>>arr[i];
    vector<vector<int>>vals(n);
    auto addr = [&](int l, int r) -> void {
        if(l<0 || r>=n) return;
        vals[l].push_back(r+1);
    };
    for(int i = 0; i<n; i++){
        int l=i-arr[i],r=l;
        addr(i-arr[i],i);
        addr(i,i+arr[i]);
    }
    bool dp[n+1]{};
    dp[0]=1;
    for(int i = 0; i<n; i++){
        for(auto u: vals[i]){
            if(dp[i]==1 && u<=n){
                dp[u]=1;
            }
        }
    }
    
    if(dp[n]){
        cout<<"YES\n";
    }else{
        cout<<"NO\n";
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(ios::failbit);
    int t;
    cin>>t;
    while(t--) solve();
}