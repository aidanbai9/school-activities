#include "bits/extc++.h"

using namespace std;

void solve(){
    int n;
    cin>>n;
    int arr[n];
    int xorv=0;
    for(int i = 0; i<n; i++){
        cin>>arr[i];
        xorv^=arr[i];
    }
    if(n==1){
        cout<<"0\n";
        return;
    }
    if(xorv==0){
        cout<<"1\n";
        return;
    }
    int ans=0;
    for(int i = 0; i<n; i++){
        if((xorv^arr[i])<arr[i]) ans++;
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