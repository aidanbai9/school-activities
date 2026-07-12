#include "bits/extc++.h"

using namespace std;

using ll = long long;

void solve(){
    int n,d;
    cin>>n>>d;
    int arr[n];
    for(int i = 0; i<n; i++) cin>>arr[i];
    ll psum[n+1]{};
    for(int i = 0; i<n; i++){
        psum[i+1]=psum[i]+arr[i];
    }
    auto rsum = [&](int l, int r) -> ll {
        return psum[r+1]-psum[l];
    };
    auto cycsum = [&](int l, int r) -> ll {
        l%=n,r%=n;
        if(l<0) l+=n;
        if(r<0) r+=n;
        if(r>=l) return rsum(l,r);
        return rsum(l,n-1)+rsum(0,r);
    };
    ll ans=0;
    for(int i = 0; i<n; i++){
        if(cycsum(i-d,i+d)<ll(2*d+1)*arr[i]){
            ans+=ll(2*d+1)*arr[i]-cycsum(i-d,i+d);
        }
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