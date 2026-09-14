#include "bits/extc++.h"

using namespace std;

void solve(){
    int n;
    cin>>n;
    int sum=0;
    for(int i = 0; i<n; i++){
        int x; cin>>x;
        sum+=x;
    }
    if(sum%4 == 0) cout<<"YES\n";
    else cout<<"NO\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(ios::failbit);
    int t;
    cin>>t;
    while(t--) solve();
}