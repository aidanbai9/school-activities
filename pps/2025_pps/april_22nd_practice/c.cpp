#include "bits/extc++.h"

using namespace std;

using ll = long long;

void solve(){
    int n,f,a,b;
    //messages,charge,spent per time,spent per stop
    cin>>n>>f>>a>>b;
    int arr[n];
    for(int i = 0; i<n; i++) cin>>arr[i];
    int pos=0;
    ll mint=0;
    for(int i = 0; i<n; i++){
        mint+=min(ll(a)*(arr[i]-pos),ll(b));
        pos=arr[i];
    }
    if(mint<f){
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