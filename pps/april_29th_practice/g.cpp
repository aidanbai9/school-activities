#include "bits/extc++.h"

using namespace std;

using ll = long long;

#define sz(x) int(std::size(x))

template <typename T>
using min_pq = priority_queue<T,vector<T>,std::greater<T>>;

constexpr int maxn = 1e4+5;

int dist[64][maxn];
bool vis[64][maxn];
bool dp[64][maxn];

void solve(){
    int n,m;
    cin>>n>>m;
    vector<int>adj[n];
    for(int i = 0; i<m; i++){
        int a,b;
        cin>>a>>b;
        a--,b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int q;
    cin>>q;
    vector<int>arr;
    map<int,int>idx;
    bool walk[n]{};
    for(int i = 0; i<q; i++){
        int x;
        cin>>x;
        x--;
        walk[x]=1;
        arr.push_back(x);
        idx[x]=i;
    }
    min_pq<array<int,3>>pq;
    for(int i = 0; i<=n; i++){
        for(int j = 0; j<64; j++){
            dist[j][i]=1e9;
            vis[j][i]=0;
            dp[j][i]=0;
        }
    }
    auto push = [&](pair<int,int>u, int d) -> void {
        if(vis[u.first][u.second]) return;
        if(d<dist[u.first][u.second]){
            dist[u.first][u.second]=d;
            pq.push({d,u.first,u.second});
        }
    };
    push({0,0},0);
    while(!pq.empty()){
        auto [d,mask,u]=pq.top();
        pq.pop();
        if(vis[mask][u]) continue;
        vis[mask][u]=1;
        if(idx.count(u)) mask|=idx[u];
        for(auto s: adj[u]){
            push({mask,s},d+1);
        }
    }
    vector<vector<int>>knap;
    for(int i = 0; i<n; i++){
        if(walk[i]) continue;
        vector<int>mask;
        int mind=1e9;
        for(int j = 0; j<64; j++){
            mind=min(mind,dist[j][i]);
        }
        assert(mind<1e9);
        for(int j = 0; j<64; j++){
            if(dist[j][i]==mind) mask.push_back(j);
        }
    }
    dp[0][0]=1;
    for(int i = 0; i<sz(knap); i++){
        for(int j = 0; j<64; j++){
            if(dp[j][i]){
                for(auto u: knap[i]){
                    dp[j|u][i+1]=1;
                }
            }
        }
    }
    int maxv=0;
    for(int i = 0; i<64; i++){
        if(dp[i][sz(knap)]) maxv=max(maxv,__builtin_popcount(i));
    }
    cout<<q-maxv<<"\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(ios::failbit);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}