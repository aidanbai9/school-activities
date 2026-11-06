#include "bits/extc++.h"

using namespace std;

using ll = long long;

#define sz(x) int(std::size(x))

struct Node {
    ll minval,sum,len;
    Node operator+(Node a){
        return {min(minval,a.minval),sum+a.sum,a.len+len};
    }
};

struct Segtree {
    int n;
    vector<int>arr;
    vector<Node>seg;
    vector<ll>flag;
    Segtree(vector<int>arrv):n(sz(arrv)),arr(arrv),seg(4*n),flag(4*n,0){
        build(1,0,n-1);
    }
    void build(int o, int l, int r){
        if(l==r){
            seg[o]={arr[l],arr[l],1};
            return;
        }
        int mid = (l+r)/2, lc = o*2, rc = o*2+1;
        build(lc,l,mid);
        build(rc,mid+1,r);
        seg[o]=seg[lc]+seg[rc];
    }
    Node appv(Node a, int flag){
        return {a.minval+flag,a.sum+flag*a.len,a.len};
    }
    void propagate(int o){
        int lc = o*2, rc = o*2+1;
        flag[lc]=flag[o];
        flag[rc]=flag[o];
        flag[o]=0;
        seg[o]=appv(seg[rc],flag[rc])+appv(seg[lc],flag[lc]);
    }
    void update(int o, int l, int r, int ql, int qr, int val){
        if(ql<=l && r<=qr){
            flag[o]+=val;
            return;
        }
        propagate(o);
        int mid = (l+r)/2, lc = o*2, rc = o*2+1;
        if(ql<=mid) update(lc,l,mid,ql,qr,val);
        if(qr>mid) update(rc,mid+1,r,ql,qr,val);
        seg[o]=appv(seg[rc],flag[rc])+appv(seg[lc],flag[lc]);
    }
    void update(int ql, int qr, int val){
        update(1,0,n-1,ql,qr,val);
    }
    Node query(int o, int l, int r, int ql, int qr, int sum){
        sum+=flag[o];
        if(ql<=l && r<=qr){
            return appv(seg[o],sum);
        }
        int mid = (l+r)/2, lc = o*2, rc = o*2+1;
        if(qr<=mid) return query(lc,l,mid,ql,qr,sum);
        if(mid<ql) return query(rc,mid+1,r,ql,qr,sum);
        return query(lc,l,mid,ql,qr,sum)+query(rc,mid+1,r,ql,qr,sum);
    }
    Node query(int ql, int qr){
        return query(1,0,n-1,ql,qr,0);
    }
};

void solve(){
    int n,q;
    cin>>n>>q;
    vector<int>arr;
    for(int i = 0; i<n; i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }
    Segtree seg(arr);
    while(q--){
        char c;
        cin>>c;
        if(c=='M'){
            int l,r;
            cin>>l>>r;
            l--,r--;
            Node val = seg.query(l,r);
            cout<<val.minval<<"\n";
        }else if(c=='S'){
            int l,r;
            cin>>l>>r;
            l--,r--;
            Node val = seg.query(l,r);
            cout<<val.sum<<"\n";
        }else{
            int l,r,x;
            cin>>l>>r>>x;
            l--,r--;
            seg.update(l,r,x);
        }
        for(int i = 0; i<n; i++){
            cout<<seg.query(i,i).minval<<" ";
        }
        cout<<"\n";
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(ios::failbit);
#ifndef LOCAL
    freopen("haybales.in","r",stdin);
    freopen("haybales.out","w",stdout);
#endif
    solve();
}