#include "bits/extc++.h"

using namespace std;

using ll = long long;

#define sz(x) int(std::size(x))

constexpr int maxn = 2e5+5;

vector<int>adj[maxn];
int deep[maxn];
ll ans=0;

void dfs(int u, int p, int depth){
    vector<int>deps;
    int dpv=depth;
    for(auto s: adj[u]){
        if(s==p) continue;
        dfs(s,u,depth+1);
        dpv=max(dpv,deep[s]);
        deps.push_back(deep[s]);
    }
    deep[u]=dpv;
    sort(deps.rbegin(),deps.rend());
    if(sz(deps)==1 || sz(deps)==0) ans++;
    else ans+=(deps[1]-depth+1);
}

void solve(){
    int n;
    cin>>n;
    for(int i = 0; i<n; i++) adj[i].clear();
    for(int i = 1; i<n; i++){
        int x;
        cin>>x;
        x--;
        adj[x].push_back(i);
        adj[i].push_back(x);
    }
    ans=0;
    dfs(0,-1,0);
    cout<<ans<<"\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(ios::failbit);
    int t;
    cin>>t;
    while(t--) solve();
}