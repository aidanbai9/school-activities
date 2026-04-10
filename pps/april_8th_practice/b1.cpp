#include "bits/extc++.h"

using namespace std;

using ll = long long;

#define sz(x) int(std::size(x))

void solve(){
    int n,k;
    cin>>n>>k;
    int arr[n];
    map<int,vector<int>>cnt;
    for(int i = 0; i<n; i++){
        cin>>arr[i];
        cnt[arr[i]].push_back(i);
    }
    int num=0;
    for(auto [val,vec]: cnt){
        if(sz(vec)<k) num+=sz(vec);
    }
    num=(num/k)*k;
    int ans[n]{};
    for(auto [val,vec]: cnt){
        if(sz(vec)>=k){
            for(int j = 0; j<k; j++){
                ans[vec[j]]=j+1;
            }
        }else{
            for(int j = 0; j<sz(vec); j++){
                if(num==0) break;
                ans[vec[j]]=num%k+1;
                num--;
            }
        }
    }
    for(int i = 0; i<n; i++){
        cout<<ans[i]<<" ";
    }
    cout<<"\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(ios::failbit);
    int t;
    cin>>t;
    while(t--) solve();
}