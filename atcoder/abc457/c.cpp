#include "bits/extc++.h"

using namespace std;

using ll = long long;

#define sz(x) int(std::size(x))

void solve(){
    int n;
    ll kv;
    cin>>n>>kv;
    kv--;
    vector<vector<int>>arr;
    for(int i = 0; i<n; i++){
        int m;
        cin>>m;
        vector<int>vals;
        for(int j = 0; j<m; j++){
            int x;
            cin>>x;
            vals.push_back(x);
        }
        arr.push_back(vals);
    }
    ll idxv=0;
    for(int i = 0; i<n; i++){
        int x;
        cin>>x;
        ll nidx=idxv+(ll(x)*sz(arr[i]));
        if(kv<nidx){
            ll cidx=kv-idxv;
            cout<<arr[i][cidx%sz(arr[i])]<<"\n";
            return;
        }
        idxv=nidx;
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(ios::failbit);
    solve();
}