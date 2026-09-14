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

bool on(int i, int j){
    return (i&(1<<j));
}

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
    int k;
    cin>>k;
    vector<int>arrv;
    for(int i = 0; i<k; i++){
        int x;
        cin>>x;
        x--;
        arrv.push_back(x);
    }
    int q;
    cin>>q;
    map<int,int>idx;
    int cntw[n]{};
    vector<int>arr;
    bool badv[k]{};
    for(int i = 0; i<q; i++){
        int x;
        cin>>x;
        x--;
        badv[x]=1;
        x=arrv[x];
        arr.push_back(x);
        idx[x]=i;
        cntw[x]++;
    }
    min_pq<array<int,3>>pq;
    for(int i = 0; i<=max(k,n); i++){
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
    /*for(int i = 0; i<n; i++){
        cout<<i<<": "<<cntw[i]<<" "<<cntd[i]<<"\n";
    }
    for(auto [a,b]: idx){
        cout<<a<<": "<<b<<"\n";
    }*/
    while(!pq.empty()){
        auto [d,mask,u]=pq.top();
        pq.pop();
        if(vis[mask][u]) continue;
        vis[mask][u]=1;
        for(auto s: adj[u]){
            int tmask=mask;
            if(idx.count(s)) tmask|=(1<<idx[s]);
            push({tmask,s},d+1);
        }
    }
    /*for(int i = 0; i<q; i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
    for(int i = 0; i<n; i++){
        cerr<<i<<"\n";
        for(int j = 0; j<(1<<q); j++){
            for(int k = 0; k<q; k++){
                if(on(j,k)) cerr<<"1";
                else cerr<<"0";
            }
            cerr<<": ";
            cerr<<dist[j][i]<<"\n";
        }
    }*/
    vector<vector<int>>knap;
    for(int i = 0; i<k; i++){
        if(badv[i]) continue;
        //cerr<<i<<": ";
        int val=arrv[i];
        //cerr<<val<<"<<\n";
        vector<int>mask;
        int mind=1e9;
        for(int j = 0; j<64; j++){
            mind=min(mind,dist[j][val]);
        }
        assert(mind<1e9);
        for(int j = 0; j<64; j++){
            if(dist[j][val]==mind) mask.push_back(j);
        }
        knap.push_back(mask);
    }
    /*for(auto u: knap){
        for(auto s: u){
            cerr<<s<<" ";
        }
        cerr<<"\n";
    }*/
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
        int curdv=0;
        if(dp[i][sz(knap)]==0) continue;
        for(int j = 0; j<6; j++){
            if(on(i,j)) curdv+=cntw[arr[j]];
            maxv=max(maxv,curdv);
        }
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