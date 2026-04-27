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
    sort(brr.begin(),brr.end());
    ll prefa[n+1]{},suffa[n+1]{};
    ll prefb[m+1]{},suffb[m+1]{};
    for(int i = 0; i<n; i++){
        prefa[i+1]=prefa[i]+arr[i];
    }
    for(int i = n-1; i>=0; i--){
        suffa[i]=suffa[i+1]+arr[i];
    }
    for(int i = 0; i<m; i++){
        prefb[i+1]=prefb[i]+brr[i];
    }
    for(int i = m-1; i>=0; i--){
        suffb[i]=suffb[i+1]+brr[i];
    }
    ll maxans=0;
    for(int i = 0; i<=n; i++){
        maxans=max(maxans,suffb[m-i]-prefa[i]+suffa[i]-prefb[n-i]);
    }
    cout<<maxans<<"\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(ios::failbit);
    int t;
    cin>>t;
    while(t--) solve();
}