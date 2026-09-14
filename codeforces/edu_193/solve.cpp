#include "bits/extc++.h"

using namespace std;

using ll = long long;

#define sz(x) int(std::size(x))

int runcnt(vector<int>arr){
    int n=sz(arr);
    vector<pair<int,int>>runs;
    for(int i = 0; i<n; i++){
        int l=i;
        while(i<n && arr[i]==arr[l]) i++;
        i--;
        runs.push_back({arr[i],i-l+1});
    }
    return sz(runs);
}

void solve(){
    int n;
    cin>>n;
    vector<int>arr;
    for(int i = 0; i<n; i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }
    int maxval=runcnt(arr);
    for(int i = 0; i<n-1; i++){
        swap(arr[i],arr[i+1]);
        maxval=max(maxval,runcnt(arr));
        swap(arr[i],arr[i+1]);
    }
    cout<<maxval<<"\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(ios::failbit);
    int t;
    cin>>t;
    while(t--) solve();
}