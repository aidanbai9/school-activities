#include "bits/extc++.h"

using namespace std;

using ll = long long;

#define sz(x) int(std::size(x))

struct Node {
    int sum;
    int maxv,minv;
    Node operator+(Node a){
        return {sum+a.sum,max(a.maxv,a.sum+maxv),min(a.minv,a.sum+minv)};
    }
};

struct Segtree {
    int n;
    vector<int>arr;
    vector<Node>seg;
    Segtree(vector<int>arrv): n(sz(arrv)),arr(arrv),seg(4*n){
        build(1,0,n-1);
    }
    void build(int o, int l, int r){
        if(l==r){
            seg[o]={arr[l],max(arr[l],0),min(0,arr[l])};
            return;
        }
        int mid = (l+r)/2, lc = o*2, rc = o*2+1;
        build(lc,l,mid);
        build(rc,mid+1,r);
        seg[o]=seg[lc]+seg[rc];
    }
    Node query(int o, int l, int r, int ql, int qr){
        if(ql<=l && r<=qr){
            return seg[o];
        }
        int mid = (l+r)/2, lc = o*2, rc = o*2+1;
        if(qr<=mid) return query(lc,l,mid,ql,qr);
        if(ql>mid) return query(rc,mid+1,r,ql,qr);
        return query(lc,l,mid,ql,qr)+query(rc,mid+1,r,ql,qr);
    }
    Node query(int ql, int qr){
        if(qr<ql) return {0,0,0};
        return query(1,0,n-1,ql,qr);
    }
};

void solve(){
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    /*
    G=-1, H=1
    good means sum>0
    so for each index i, we want starting from end of range (k characters away)
    we want to find last j such that [i,j]>0, so this means
    [i,j] + [j+1,end] = sum , [j+1,end] < sum, so min suffix sum
    j+1 to end must be < sum
    */
    vector<int>trs(n),trs2(n);
    vector<int>wet(n);
    for(int i = 0; i<n; i++){
        if(s[i]=='H') wet[i]=1;
        else wet[i]=-1;
    }
    int ssum[n+1]{};
    auto rsum = [&](int l, int r) -> int {
        return ssum[l]-ssum[r+1];
    };
    for(int i = n-1; i>=0; i--){
        if(s[i]=='H') ssum[i]=ssum[i+1]+1;
        else ssum[i]=ssum[i+1]-1;
    }
    {
        Segtree seg(wet);
        for(int i = n-1; i>=0; i--){
            int l = -1, r = min(i+k-1,n-1)+2;
            int sumv=rsum(i,min(i+k-1,n-1));
            auto check = [&](int x) -> bool {
                return (seg.query(x,min(i+k-1,n-1)).minv<sumv);
            };
            while(l<r-1){
                int mid = (l+r)/2;
                if(check(mid)){
                    l=mid;
                }else{
                    r=mid;
                }
            }
            if(l<i){
                trs[i]=n+1;
            }else{
                trs[i]=l;
            }
        }
    }

    /*
    G=-1, H=1
    bad means sum<=0
    so for each index i, we want starting from end of range (k characters away)
    we want to find last j such that [i,j]<=0, so this means
    [i,j] + [j+1,end] = sum , [j+1,end] >= sum, so max suffix sum
    j+1 to end must be >= sum
    */
    {
        Segtree seg(wet);
        for(int i = n-1; i>=0; i--){
            int l = -1, r = min(i+k-1,n-1)+2;
            int sumv=rsum(i,min(i+k-1,n-1));
            auto check = [&](int x) -> bool {
                return (seg.query(x,min(i+k-1,n-1)).maxv>=sumv);
            };
            while(l<r-1){
                int mid = (l+r)/2;
                if(check(mid)){
                    l=mid;
                }else{
                    r=mid;
                }
            }
            if(l<=i){
                trs2[i]=n+1;
            }else{
                trs2[i]=l;
            }
        }
    }
    int dp[n+1]{};
    for(auto &u: dp) u=1e9;
    dp[n]=0;
    for(int i = 0; i<n; i++){
        cout<<i<<" "<<trs[i]<<" "<<trs2[i]<<"\n";
    }
    for(int i = n-1; i>=0; i--){
        if(trs2[i]!=n+1){
            dp[i]=min(dp[i],dp[trs2[i]]+1);
        }
        if(trs[i]!=n+1){
            dp[i]=min(dp[i],dp[trs[i]]);
        }
    }
    cout<<dp[0]<<"\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(ios::failbit);
#ifndef LOCAL
    freopen("redistricting.in","r",stdin);
    freopen("redistricting.out","w",stdout);
#endif
    solve();
}