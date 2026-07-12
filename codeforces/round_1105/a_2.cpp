#include "bits/extc++.h"

using namespace std;

void solve(){
    int n,k;
    cin>>n>>k;
    int val=n/k,cntv=0;
    if(n<=k){
        cout<<n<<"\n";
        return;
    }
    for(int i = 0; i<25; i++){
        if((1<<i)-1 <= val) cntv=i;
    }
    int ans=k*cntv;
    ans+=(n-k*((1<<cntv)-1))/(1<<cntv);
    cout<<ans<<"\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(ios::failbit);
    int t;
    cin>>t;
    while(t--) solve();
}