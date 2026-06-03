#include "bits/extc++.h"

using namespace std;

void solve(){
    int n;
    cin>>n;
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
    int a,b;
    cin>>a>>b;
    cout<<arr[a-1][b-1]<<"\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(ios::failbit);
    solve();
}