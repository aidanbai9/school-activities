#include "bits/extc++.h"

using namespace std;

using ll = long long;

#define sz(x) int(std::size(x))

constexpr ll mod = 998244353;

ll bpow(ll base, ll exp){
    base%=mod;
    ll ans=1;
    while(exp){
        if(exp%2) ans=(ans*base)%mod;
        base=(base*base)%mod;
        exp/=2;
    }
    return ans;
}

ll inv(ll x){
    return bpow(x,mod-2);
}

constexpr ll maxn = 1e6+5;

ll fac[maxn],invfac[maxn];

ll choose(int n, int k){
    if(n==k) return 1;
    ll ans=(fac[n]*invfac[k])%mod;
    ans=(ans*invfac[n-k])%mod;
    return ans;
}

void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int cnt[2]{},runs[2]{};
    for(auto u: s) cnt[(u-'0')]++;
    for(int i = 0; i<n; i++){
        int l=i;
        while(i<n && s[l]==s[i]) i++;
        i--;
        runs[(s[i]-'0')]++;
    }
    ll ans0=choose(cnt[0]-1,runs[0]-1);
    ll ans1=choose(cnt[1]-1,runs[1]-1);
    ll ans=(ans0*ans1)%mod;
    cout<<ans<<"\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(ios::failbit);
    fac[0]=1,invfac[0]=1;
    for(int i = 1; i<maxn; i++){
        fac[i]=(fac[i-1]*i)%mod;
        invfac[i]=inv(fac[i]);
    }
    int t;
    cin>>t;
    while(t--) solve();
}
/*
thoughts section:
1. obvious observations:
    a. number of 1's/0's is invariant
    b. first/last element is invariant
    c. # runs is invariant
2. claim: any string with those invariant work
    a. just fix stuff run by run
    b. you can do the donate all but 1 strat until it runs out
3. to count this do some dp
    a. wait is this just like stars and bars lmao
    b. yeah i think this just is lmao
    c. stars and bars on 1's then stars and bars on 0's
    d. M sections X elements is X-M stars, M-1 bars
    e. formula is choose(X-1,M-1)
*/