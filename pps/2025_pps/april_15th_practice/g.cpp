#include "bits/extc++.h"

using namespace std;

using ll = long long;

constexpr int maxn = 2e5+5;

int n,m;
vector<int>adj[maxn];
int dist[maxn];
int dpval[2][maxn];

int dp(int tv, int u){
    if(dpval[tv][u]!=-1) return dpval[tv][u];
    int minans=dist[u];
    for(auto s: adj[u]){
        if(dist[s]>dist[u]) minans=min(minans,dp(tv,s));
        else if(tv) minans=min(minans,dp(0,s));
    }
    return dpval[tv][u]=minans;
}

void solve(){
    cin>>n>>m;
    for(int i = 0; i<n; i++){
        dist[i]=-1;
        dpval[0][i]=-1,dpval[1][i]=-1;
        adj[i].clear();
    }
    for(int i = 0; i<m; i++){
        int a,b;
        cin>>a>>b;
        a--,b--;
        adj[a].push_back(b);
    }
    //figure out distance to 1
    queue<int>q;
    auto push = [&](int u, int d) -> void {
        if(dist[u]==-1){
            dist[u]=d;
            q.push(u);
        }
    };
    push(0,0);
    while(!q.empty()){
        auto u=q.front();
        q.pop();
        for(auto s: adj[u]){
            push(s,dist[u]+1);
        }
    }
    for(int i = 0; i<n; i++){
        cout<<dp(1,i)<<" ";
    }
    cout<<"\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(ios::failbit);
    int t;
    cin>>t;
    while(t--) solve();
}