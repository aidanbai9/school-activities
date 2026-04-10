#include "bits/extc++.h"

using namespace std;

using ll = long long;

#define sz(x) int(std::size(x))

struct Node {
    ll sum,len;
    Node operator+(Node a){
        return {sum+a.sum,len+a.len};
    }
};

struct Flag {
    ll setv,addv;
    Flag operator+(Flag a){
        if(setv!=-1) return {setv,addv};
        return {a.setv,addv+a.addv};
    }
};

struct Segtree {
    int n;
    vector<int>arr;
    vector<Node>seg;
    vector<Flag>flag;
    Segtree(vector<int>arrv):n(sz(arrv)),arr(arrv),seg(4*n),flag(4*n,{-1,0}){
        build(1,0,n-1);
    }
    void build(int o, int l, int r){
        if(l==r){
            seg[o]={arr[l],1};
            return;
        }
        int mid = (l+r)/2, lc = o*2, rc = o*2+1;
        build(lc,l,mid);
        build(rc,mid+1,r);
        seg[o]=seg[lc]+seg[rc];
    }
    Node value(Node x, Flag fl){
        if(fl.setv==-1){
            return {(x.len*fl.addv+x.sum),x.len};
        }
        return {x.len*fl.addv+x.len*fl.setv,x.len};
    }
    void propagate(int o){
        int lc = o*2, rc = o*2;
        seg[o]=value(seg[o],flag[o]);
        flag[lc]=flag[o]+flag[lc];
        flag[rc]=flag[o]+flag[rc];
        flag[o]={-1,0};
    }
    void update(int o, int l, int r, int ql, int qr, Flag val){
        if(ql<=l && r<=qr){
            flag[o]=val+flag[o];
            return;
        }
        propagate(o);
        int mid = (l+r)/2, lc = o*2, rc = o*2+1;
        if(ql<=mid) update(lc,l,mid,ql,qr,val);
        if(qr>=mid+1) update(rc,mid+1,r,ql,qr,val);
        seg[o]=value(seg[lc],flag[lc])+value(seg[rc],flag[rc]);
    }
    void update(int ql, int qr, Flag val){
        update(1,0,n-1,ql,qr,val);
    }
    Node query(int o, int l, int r, int ql, int qr, Flag sum){
        sum=sum+flag[o];
        if(ql<=l && r<=qr){
            return value(seg[o],sum);
        }
        int mid = (l+r)/2, lc = o*2, rc = o*2+1;
        if(qr<=mid) return query(lc,l,mid,ql,qr,sum);
        if(ql>=mid+1) return query(rc,mid+1,r,ql,qr,sum);
        return query(lc,l,mid,ql,qr,sum)+query(rc,mid+1,r,ql,qr,sum);
    }
    Node query(int ql, int qr){
        return query(1,0,n-1,ql,qr,{-1,0});
    }
};

void solve(){
    int n,q;
    cin>>n>>q;
    vector<int>arr(n);
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    Segtree seg(arr);
    while(q--){
        int t,l,r;
        cin>>t>>l>>r;
        l--,r--;
        if(t==1){
            int x;
            cin>>x;
            seg.update(l,r,{-1,x});
        }else if(t==2){
            int x;
            cin>>x;
            seg.update(l,r,{x,0});
        }else{
            cout<<seg.query(l,r).sum<<"\n";
        }
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(ios::failbit);
    solve();
}