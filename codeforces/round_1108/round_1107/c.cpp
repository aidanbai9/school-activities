#include "bits/extc++.h"

using namespace std;

using ll = long long;

constexpr ll mod = 1e9+7;

constexpr int maxn = 2e5+5;

ll bpow(ll base, ll exp){
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

ll fac[maxn],invfac[maxn];

ll choose(int n, int k){
    ll ans=(fac[n]*invfac[k])%mod;
    ans=(ans*invfac[n-k])%mod;
    return ans;
}

void solve(){
    int n;
    cin>>n;
    int arr[n]{};
    for(int i = 0; i<n; i++) cin>>arr[i];
    map<int,int>cnt;
    map<int,int>che,cho;
    for(int i = 0; i<n; i++) cnt[arr[i]]++;
    for(auto [a,b]: cnt){
        ll chev=0,chov=0;
        for(int i = 0; i<=b; i+=2) chev=(chev+choose(b,i))%mod;
        for(int i = 1; i<=b; i+=2) chov=(chov+choose(b,i))%mod;
        che[a]=chev,cho[a]=chov;
    }
    //evenans
    ll eans=1;
    for(auto [a,b]: cnt){
        eans=(eans*che[a])%mod;
    }
    ll oans=0;
    for(auto [a,b]: cnt){
        if(a==-1) continue;
        if(che[a+1]==0 || arr[0]!=-1) continue;
        ll ov=(eans*inv(che[a]))%mod;
        ov=(ov*inv(che[a+1]))%mod;
        ov=(ov*inv(che[-1]))%mod;
        ov=(ov*cho[a])%mod;
        ov=(ov*cho[a+1])%mod;
        ov=(ov*cho[-1])%mod;
        oans=(oans+ov)%mod;
    }
    ll ans=(oans+eans)%mod;
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