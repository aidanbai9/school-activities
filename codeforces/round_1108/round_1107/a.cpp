#include "bits/extc++.h"

using namespace std;

void solve(){
    int n;
    cin>>n;
    for(int i = 0; i<n; i++){
        if(i%2==0){
            cout<<i+2<<" ";
        }else{
            cout<<i<<" ";
        }
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