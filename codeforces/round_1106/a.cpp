#include "bits/extc++.h"

using namespace std;

void solve(){
    int n,k;
    cin>>n>>k;
    vector<int>arr(n),brr(n);
    for(int i = 0; i<n; i++) cin>>arr[i];
    for(int i = 0; i<n; i++) cin>>brr[i];
    int cost1=0,cost2=k;
    for(int i = 0; i<n; i++){
        if(arr[i]<brr[i]) cost1=1e9;
        else cost1+=(arr[i]-brr[i]);
    }
    sort(arr.begin(),arr.end());
    sort(brr.begin(),brr.end());
    for(int i = 0; i<n; i++){
        if(arr[i]<brr[i]) cost2=1e9;
        else cost2+=(arr[i]-brr[i]);
    }
    if(cost1<1e9) cout<<cost1<<"\n";
    else if(cost2<1e9) cout<<cost2<<"\n";
    else cout<<"-1\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(ios::failbit);
    int t;
    cin>>t;
    while(t--) solve();
}