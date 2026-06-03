#include "bits/extc++.h"

using namespace std;

using ll = long long;

#define sz(x) int(std::size(x))

void solve(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i = 0; i<n; i++) cin>>arr[i];
    sort(arr.rbegin(),arr.rend());
    ll maxans=arr.back();
    ll sum=0;
    for(int i = 0; i<n; i++){
        arr.back()+=sum;
        sum-=arr.back();
        arr.pop_back();
        if(sz(arr)) maxans=max(maxans,sum+arr.back());
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