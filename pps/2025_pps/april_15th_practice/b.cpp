#include "bits/extc++.h"

using namespace std;

using ll = long long;

#define sz(x) int(std::size(x))

void solve(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i<n; i++) cin>>arr[i];
    int sum=0;
    for(int i = 0; i<n; i++) sum+=arr[i];
    int num2=0;
    for(int i = 0; i<n; i++){
        num2+=(arr[i]==2);
    }
    if(sum%2!=0){
        cout<<"NO\n";
        return;
    }
    if(num2==n && n%2==1){
        cout<<"NO\n";
        return;
    }
    cout<<"YES\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(ios::failbit);
    int t;
    cin>>t;
    while(t--) solve();
}