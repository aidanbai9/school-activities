#include "bits/extc++.h"

using namespace std;

using ll = long long;

#define sz(x) int(std::size(x))

constexpr int maxn = 105;
vector<int>adj[maxn];
int n,kv;
int dp[maxn][maxn];
ll dp2[maxn][maxn];
constexpr ll mod = 1e9+7;

void dfs(int u, int p){
    dp[u][0]=1;
    for(auto s: adj[u]){
        if(s==p) continue;
        dfs(s,u);
        for(int i = 0; i<n; i++){
            dp[u][i+1]+=dp[s][i];
        }
    }
}

void solve(){
    cin>>n>>kv;
    for(int i = 0; i<n; i++) adj[i].clear();
    for(int i = 0; i<n-1; i++){
        int a,b;
        cin>>a>>b;
        a--,b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    if(kv==2){
        cout<<(n)*(n-1)/2<<"\n";
        return;
    }
    ll ans=0;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            for(int k = 0; k<=n; k++){
                dp[j][k]=0;
            }
        }
        dfs(i,-1);
        for(int val = 0; val<=n; val++){
            for(int j = 0; j<n; j++) dp2[sz(adj[i])][j]=0;
            if(sz(adj[i])<kv) continue;
            dp2[sz(adj[i])][0]=1;
            //which one how many in a row
            for(int j = sz(adj[i])-1; j>=0; j--){
                for(int k = 0; k<=sz(adj[i]); k++){
                    dp2[j][k]=dp2[j+1][k];
                    if(k!=0){
                        dp2[j][k]=(dp2[j][k]+dp2[j+1][k-1]*dp[adj[i][j]][val])%mod;
                    }
                }
            }
            ans=(ans+dp2[0][kv])%mod;
        }
    }
    cout<<ans<<"\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(ios::failbit);
    int t;
    cin>>t;
    while(t--) solve();
}