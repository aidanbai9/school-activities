#include "bits/extc++.h"

using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int>arr;
    for(int i = 0; i<n; i++){
        int x;
        cin>>x;
        arr.push_back(n-1-x);
    }
    int l=-1,r=n;
    auto check = [&](int x) -> bool {
        vector<int>arrv;
        for(int i = 0; i<x; i++){
            arrv.push_back(arr[i]);
        }
        sort(arrv.begin(),arrv.end());
        for(int i = 0; i<x; i++){
            if(i==arrv[i]){
                return true;
            }
        }
        return false;
    };
    while(l<r-1){
        int mid = (l+r)/2;
        if(check(mid)){
            r=mid;
        }else{
            l=mid;
        }
    }
    cout<<n-r<<"\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(ios::failbit);
#ifndef LOCAL
    freopen("greedy.in","r",stdin);
    freopen("greedy.out","w",stdout);
#endif
    solve();
}