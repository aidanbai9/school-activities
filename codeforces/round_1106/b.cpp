#include "bits/extc++.h"

using namespace std;

using ll = long long;

void solve(){
    int n;
    cin>>n;
    ll ans=0;
    for(int i = 1; i<=n; i++){
        ans+=ll(n/i)*(n/i);
    }
    cout<<ans<<"\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(ios::failbit);
    int t;
    cin>>t;
    while(t--) solve();
}