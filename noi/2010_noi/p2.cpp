#include "bits/extc++.h"

using namespace std;

using ll = long long;

constexpr int maxn = 2e5+5;

array<ll,2>succ[20][maxn];

void solve(){
    int n,k,l,r;
    cin>>n>>k>>l>>r;
    int arr[n];
    ll psum[n+1]{};
    for(int i = 0; i<n; i++){
        cin>>arr[i];
        psum[i+1]=psum[i]+arr[i];
    }
    for(int i = 0; i<=n; i++){
        succ[0][i]={psum[i],i};
    }
    for(int i = 1; i<20; i++){
        for(int j = 0; j<=n; j++){
            succ[i][j]=max(succ[i-1][j],succ[i-1][min(n,j+(1<<(i-1)))]);
        }
    }
    auto maxv = [&](int l, int r) -> array<ll,2> {
        int lgv = __lg(r-l+1);
        return max(succ[lgv][l],succ[lgv][r-(1<<lgv)+1]);
    };
    set<array<ll,5>>sv;
    auto push = [&](int lb, int rb, int i) -> void {
        if(rb<lb) return;
        array<ll,2> val=maxv(lb,rb);
        val[0]-=psum[i];
        sv.insert({val[0],val[1],lb,rb,i});
    };
    for(int i = 0; i<n; i++){
        if(i+l>n) break;
        int lb=i+l,rb=min(i+r,n);
        push(lb,rb,i);
    }
    ll ans=0;
    for(int i = 0; i<k; i++){
        auto [val,idx,lb,rb,iv] = *(--(sv.end()));
        ans+=val;
        push(lb,idx-1,iv);
        push(idx+1,rb,iv);
    }
    cout<<ans<<"\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(ios::failbit);
    solve();
}