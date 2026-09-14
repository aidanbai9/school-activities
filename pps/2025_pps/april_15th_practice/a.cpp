#include "bits/extc++.h"

using namespace std;

using ll = long long;

#define sz(x) int(std::size(x))

void solve(){
    int w,h,n;
    cin>>w>>h>>n;
    ll cnt=1;
    while(w%2==0){
        cnt*=2;
        w/=2;
    }
    while(h%2==0){
        cnt*=2;
        h/=2;
    }
    if(cnt>=n){
        cout<<"YES\n";
    }else{
        cout<<"NO\n";
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(ios::failbit);
    int t;
    cin>>t;
    while(t--) solve();
}