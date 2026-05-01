#include "bits/extc++.h"

using namespace std;

using ll = long long;

#define sz(x) int(std::size(x))

constexpr int maxn = 3e5+5;
set<int>hv;
ll ans=0;

struct Upd {
    int a,b,c;
};

struct DSUt {
    int n;
    vector<int>par;
    DSUt(int nv):n(nv),par(n,0){
        for(int i = 0; i<n; i++) par[i]=i;
    } 
    int find(int x){
        if(par[x]==x) return x;
        return par[x]=find(par[x]);
    }
    bool issame(int a, int b){
        a=find(a),b=find(b);
        return (a==b);
    }
    void merge(int a, int b){
        a=find(a),b=find(b);
        par[a]=b;
    }
};

struct DSU {
    int n;
    vector<int>par,siz,flag;
    vector<array<int,5>>hist;
    DSUt dsu;
    DSU(int nv):n(nv),par(n,0),siz(n,1),flag(n,-1),dsu(n){
        for(int i = 0; i<n; i++){
            par[i]=i;
            if(hv.count(i)) flag[i]=i;
        }
    } 
    int find(int x){
        if(par[x]==x) return x;
        return find(par[x]);
    }
    void merge(int a, int b, int c){
        a=find(a);
        b=find(b);
        if(siz[a]>siz[b]) swap(a,b);
        hist.push_back({a,b,par[a],siz[b],flag[b]});
        par[a]=b;
        if(flag[b]!=-1 && flag[a]!=-1){
            if(!dsu.issame(flag[a],flag[b])){
                ans+=c;
                dsu.merge(flag[a],flag[b]);
            }
        }
        if(flag[b]==-1) flag[b]=flag[a];
        if(a!=b) siz[b]+=siz[a];
    }
    void rollback(){
        auto [a,b,p,s,fl] = hist.back();
        par[a]=p;
        siz[b]=s;
        flag[b]=fl;
        hist.pop_back();
    }
};

struct Segtree {
    int n;
    vector<vector<Upd>>val;
    DSU dsu;
    Segtree(int nv, int sizdsu): n(nv),val(4*n),dsu(sizdsu){};
    void update(int o, int l, int r, int ql, int qr, Upd upd){
        if(ql<=l && r<=qr){
            val[o].push_back(upd);
            return;
        }
        int mid = (l+r)/2, lc = o*2, rc = o*2+1;
        if(ql<=mid) update(lc,l,mid,ql,qr,upd);
        if(qr>mid) update(rc,mid+1,r,ql,qr,upd);
    }
    void update(int ql, int qr, Upd upd){
        update(1,0,n-1,ql,qr,upd);
    }
    void dfs(int o, int l, int r){
        for(auto u: val[o]){
            dsu.merge(u.a,u.b,l);
        }
        if(l!=r){
            int mid = (l+r)/2, lc = o*2, rc = o*2+1;
            dfs(lc,l,mid);
            dfs(rc,mid+1,r);
        }
        for(auto u: val[o]){
            dsu.rollback();
        }
    }
    void dfs(){
        dfs(1,0,n-1);
    }
};

void solve(){
    int n,m,q;
    hv.clear();
    cin>>n>>m>>q;
    ans=0;
    vector<pair<int,int>>adj[n];
    vector<array<int,3>>edges;
    for(int i = 0; i<m; i++){
        int a,b,c;
        cin>>a>>b>>c;
        a--,b--;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
        edges.push_back({c,a,b});
    }
    for(int i = 0; i<q; i++){
        int x;
        cin>>x;
        x--;
        hv.insert(x);
    }
    Segtree seg(m+1,n);
    for(auto [c,a,b]: edges){
        if(c!=0){
            seg.update(0,c-1,{a,b,c});
        }
        if(c!=m){
            seg.update(c+1,m,{a,b,c});
        }
    }
    seg.dfs();
    vector<int>hvals;
    for(auto u: hv) hvals.push_back(u);
    for(auto u: hvals){
        if(!seg.dsu.dsu.issame(u,hvals[0])){
            cout<<"-1\n";
            return;
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