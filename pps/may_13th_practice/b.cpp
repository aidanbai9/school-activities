#include "bits/extc++.h"

using namespace std;

using ll = long long;

#define sz(x) int(std::size(x))

void solve(){
    ll x,n;
    cin>>x>>n;
    auto sumv = [&](int mv) -> ll {
        ll maxv=n;
        if(maxv<mv) return 0;
        while(maxv%4!=mv) maxv--;
        return (mv+maxv)*((maxv-mv)/4+1)/2;
    };
    ll sum=0;
    sum+=sumv(2);
    sum+=sumv(3);
    sum-=sumv(1);
    sum-=sumv(0);
    if(x%2==0){
        cout<<x+sum<<"\n";
    }else{
        cout<<x-sum<<"\n";
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(ios::failbit);
    int t;
    cin>>t;
    while(t--) solve();
}