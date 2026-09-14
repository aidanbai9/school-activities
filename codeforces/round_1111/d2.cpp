#include "bits/extc++.h"

using namespace std;

#define sz(x) int(std::size(x))

struct Node {
    int minv,maxv;
    Node operator+(Node a){
        return {min(minv,a.minv),max(maxv,a.maxv)};
    }
};

struct Segtree {
    int n;
    vector<int>arr;
    vector<Node>seg;
    Segtree(vector<int>arrv,int nv):n(nv),arr(arrv),seg(4*n){
        build(1,0,n-1);
    }
    void build(int o, int l, int r){
        if(l==r){
            if(l<sz(arr)) seg[o]={arr[l],arr[l]};
            else seg[o]={int(2e9),-1};
            return;
        }
        int mid = (l+r)/2, lc = o*2, rc = o*2+1;
        build(lc,l,mid);
        build(rc,mid+1,r);
        seg[o]=seg[lc]+seg[rc];
    }
    void update(int o, int l, int r, int idx, int val){
        if(l==r){
            seg[o]={val,val};
            return;
        }
        int mid = (l+r)/2, lc = o*2, rc = o*2+1;
        if(idx<=mid) update(lc,l,mid,idx,val);
        else update(rc,mid+1,r,idx,val);
        seg[o]=seg[lc]+seg[rc];
    }
    void update(int idx, int val){
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
    int nv=(1<<(__lg(n)+1));
    vector<int>arr(n);
    for(int i = 0; i<n; i++) cin>>arr[i];
    Segtree seg(arr,nv);
    int cnt[21]{};
    int numsec[21]{};
    for(int i = 0; i<21; i++){
        for(int j = (1<<i); j<n; j+=(1<<i)){
            int cmin=seg.query(j,j+(1<<i)-1).minv;
            int pmax=seg.query(j-(1<<i),j-1).maxv;
            cnt[i]+=(pmax<=cmin);
            numsec[i]++;
        }
    }
    auto ans = [&]() -> void {
        int r=20;
        for(;r>=0; r--){
            if(numsec[r]!=cnt[r]) break;
        }
        r++;
        cout<<(1<<r)/2<<"\n";
    };

    auto getpv = [&](int i, int idx) -> int {
        int cl=idx,cr=(idx+(1<<i))-1;
        int pl=idx-(1<<i),pr=idx-1;
        if(pl<0) return 0;
        int cmin=seg.query(cl,cr).minv;
        int pmax=seg.query(pl,pr).maxv;
        return (pmax<=cmin);
    };

    auto getnv = [&](int i, int idx) -> int {
        int cl=idx,cr=idx+(1<<i)-1;
        int nl=idx+(1<<i),nr=nl+(1<<i)-1;
        if(nl>=n) return 0;
        int cmin=seg.query(nl,nr).minv;
        int pmax=seg.query(cl,cr).maxv;
        return (pmax<=cmin);
    };
    ans();
    while(q--){
        int a,b;
        cin>>a>>b;
        for(int i = 0; i<21; i++){
            int cl=(a/(1<<i))*(1<<i);
            cnt[i]-=getpv(i,cl);
            cnt[i]-=getnv(i,cl);
        }
        seg.update(a,b);
        for(int i = 0; i<21; i++){
            int cl=(a/(1<<i))*(1<<i);
            cnt[i]+=getpv(i,cl);
            cnt[i]+=getnv(i,cl);
        }
        ans();
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(ios::failbit);
    int t;
    cin>>t;
    while(t--) solve();
}