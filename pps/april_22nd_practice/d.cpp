#include "bits/extc++.h"

using namespace std;

using ll = long long;

void solve(){
    int n,m;
    cin>>n>>m;
    vector<int>arr(n),brr(m);
    for(int i = 0; i<n; i++) cin>>arr[i];
    for(int i = 0; i<m; i++) cin>>brr[i];
    sort(arr.begin(),arr.end());
    sort(brr.rbegin(),brr.rend());
    vector<ll>la,ra;
    ll sum=0;
    
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(ios::failbit);
    int t;
    cin>>t;
    while(t--) solve();
}