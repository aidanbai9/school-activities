#include "bits/extc++.h"

using namespace std;

using ll = long long;

#define sz(x) int(std::size(x))

constexpr ll INF = 1e12+5;

struct Node {
    ll maxv,minv;
    Node operator+(Node a){
        return {max(maxv,a.maxv),min(minv,a.minv)};
    }
};

struct Segtree {
    int n;
    vector<Node>arr,seg;
    Segtree(int nv):n(nv),arr(n,{ll(0),ll(INF)}),seg(4*n){
        build(1,0,n-1);
    }
    void build(int o, int l, int r){
        if(l==r){
            seg[o]=arr[l];
            return;
        }
        int mid = (l+r)/2, lc = o*2, rc = o*2+1;
        build(lc,l,mid);
        build(rc,mid+1,r);
        seg[o]=seg[lc]+seg[rc];
    }
    void update(int o, int l, int r, int idx, ll val){
        if(l==r){
            seg[o]=seg[o]+Node({val,val});
            return;
        }
        int mid = (l+r)/2, lc = o*2, rc = o*2+1;
        if(idx<=mid) update(lc,l,mid,idx,val);
        else update(rc,mid+1,r,idx,val);
        seg[o]=seg[lc]+seg[rc];
    }
    void update(int idx, ll val){
        update(1,0,n-1,idx,val);
    }
    Node query(int o, int l, int r, int ql, int qr){
        if(ql<=l && r<=qr){
            return seg[o];
        }
        int mid = (l+r)/2, lc = o*2, rc = o*2+1;
        if(qr<=mid) return query(lc,l,mid,ql,qr);
        if(ql>=mid+1) return query(rc,mid+1,r,ql,qr);
        return query(lc,l,mid,ql,qr)+query(rc,mid+1,r,ql,qr);
    }
    Node query(int ql, int qr){
        return query(1,0,n-1,ql,qr);
    }
};

void solve(){
    int n,q;
    cin>>n>>q;
    vector<array<ll,4>>evnt;
    for(int i = 0; i<n; i++){
        int x,y,c;
        cin>>x>>y>>c;
        evnt.push_back({x,y,0,c});
    }
    map<pair<int,int>,vector<int>>qus;
    for(int i = 0; i<q; i++){
        int a,b;
        cin>>a>>b;
        qus[{a,b}].push_back(i);
        evnt.push_back({a,b,1,0});
    }
    map<pair<int,int>,ll>ansv;
    map<int,int>cmpy;
    vector<int>yvs;
    {
        set<int>yv;
        for(auto [a,b,c,d]: evnt){
            yv.insert(b);
            if(c==1){
                ansv[{a,b}]=abs(b-a);
            }
        }
        int idx=0;
        for(auto u: yv){
            cmpy[u]=idx;
            yvs.push_back(u);
            idx++;
        }
    }
    {
        //first quadrant
        sort(evnt.rbegin(),evnt.rend());
        Segtree seg(sz(yvs));
        for(auto [x,y,type,d]: evnt){
            if(type==0){
                //sling
                seg.update(cmpy[y],x+y+d);
            }else{
                ansv[{x,y}]=min(ansv[{x,y}],seg.query(cmpy[y],sz(yvs)-1).minv-x-y);
            }
        }
    }
    {
        //third quadrant
        sort(evnt.begin(),evnt.end());
        Segtree seg(sz(yvs));
        for(auto [x,y,type,d]: evnt){
            if(type==0){
                //sling
                seg.update(cmpy[y],-x-y+d);
            }else{
                ansv[{x,y}]=min(ansv[{x,y}],seg.query(0,cmpy[y]).minv+x+y);
            }
        }
    }

    {
        //second quadrant
        for(auto &[a,b,c,d]: evnt) b=-b;
        sort(evnt.begin(),evnt.end());
        for(auto &[a,b,c,d]: evnt) b=-b;
        Segtree seg(sz(yvs));
        for(auto [x,y,type,d]: evnt){
            if(type==0){
                //sling
                seg.update(cmpy[y],-x+y+d);
            }else{
                ansv[{x,y}]=min(ansv[{x,y}],seg.query(cmpy[y],sz(yvs)-1).minv+x-y);
            }
        }
    }

    {
        //fourth quadrant
        for(auto &[a,b,c,d]: evnt) b=-b;
        sort(evnt.rbegin(),evnt.rend());
        for(auto &[a,b,c,d]: evnt) b=-b;
        Segtree seg(sz(yvs));
        for(auto [x,y,type,d]: evnt){
            if(type==0){
                //sling
                seg.update(cmpy[y],+x-y+d);
            }else{
                ansv[{x,y}]=min(ansv[{x,y}],seg.query(0,cmpy[y]).minv-x+y);
            }
        }
    }
    {
        //output
        vector<int>ans(q);
        for(auto [a,b]: qus){
            for(auto v: b){
                ans[v]=ansv[a];
            }
        }
        for(auto u: ans){
            cout<<u<<"\n";
        }
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(ios::failbit);
#ifndef LOCAL
    freopen("slingshot.in","r",stdin);
    freopen("slingshot.out","w",stdout);
#endif
    solve();
}