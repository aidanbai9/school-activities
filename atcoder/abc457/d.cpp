#include "bits/extc++.h"

using namespace std;

using ll = __int128_t;

#define sz(x) int(std::size(x))

void solve(){
    long long n,kv;
    cin>>n>>kv;
    ll arr[n];
    for(int i = 0; i<n; i++){
        long long x;
        cin>>x;
        arr[i]=x;
    }
    ll l=-1,r=3e18;
    auto dist = [&](ll a, ll b, ll val) -> ll {
        if(a>=b) return 0;
        ll diff=b-a;
        return (diff+val-1)/val;
    };
    auto check = [&](ll mid) -> bool {
        ll sum=0;
        for(int i = 0; i<n; i++){
            sum+=dist(arr[i],mid,i+1);
        }
        return (sum<=kv);
    };
    while(l<r-1){
        ll mid = (l+r)/2;
        if(check(mid)){
            l=mid;
        }else{
            r=mid;
        }
    }
    long long ans=l;
    cout<<ans<<"\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(ios::failbit);
    solve();
}