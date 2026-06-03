#include "bits/extc++.h"

using namespace std;

using ll = long long;

#define sz(x) int(std::size(x))

void solve(){
    int n,q;
    cin>>n>>q;
    vector<int>arr(n);
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    int sumv=0;
    for(int i = 0; i<n; i++){ if(i%2==1) sumv+=arr[i]; }
    cout<<sumv<<"\n";
    while(q--){
        int idx,val;
        cin>>idx>>val;
        if(idx%2==1) sumv-=arr[idx];
        arr[idx]=val;
        if(idx%2==1) sumv+=arr[idx];
        cout<<sumv<<"\n";
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(ios::failbit);
    solve();
}