#include "bits/extc++.h"

using namespace std;

void solve(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i<n; i++) cin>>arr[i];
    if(n%2==1){
        cout<<"NO\n";
        return;
    }
    int maxb=1e9,minb=-1;
    for(int i = 0; i<n; i+=2){
        maxb=min(maxb,arr[i]);
        minb=max(minb,arr[i+1]);
    }
    if(minb<maxb-1){
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