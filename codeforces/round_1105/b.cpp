#include "bits/extc++.h"

using namespace std;

using ll = long long;

constexpr ll mod = 998244353;

ll bpow(ll base, ll exp){
    ll ans=1;
    while(exp){
        if(exp%2) ans=(ans*base)%mod;
        base=(base*base)%mod;
        exp/=2;
    }
    return ans;
}

void solve(){
    int n,m,r,c;
    cin>>n>>m>>r>>c;
    ll val=ll(r-1)*m+ll(c-1)*(n)-ll(c-1)*(r-1);
    cout<<bpow(2,val)<<"\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(ios::failbit);
    int t;
    cin>>t;
    while(t--)  solve();
}