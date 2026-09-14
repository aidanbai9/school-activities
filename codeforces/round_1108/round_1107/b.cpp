#include "bits/extc++.h"

using namespace std;

using ll = long long;

void solve(){
    int n;
    cin>>n;
    if(n==1){
        cout<<2<<"\n";
        return;
    }
    if(n==2){
        cout<<"-1\n";
        return;
    }
    cout<<"1 2 3 ";
    ll val=6;
    for(int i = 0; i<n-3; i++){
        cout<<val<<" ";
        val*=2;
    }
    cout<<"\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(ios::failbit);
    int t;
    cin>>t;
    while(t--) solve();
}