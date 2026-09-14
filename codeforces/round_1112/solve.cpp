#include "bits/extc++.h"

using namespace std;

using ll = long long;

constexpr ll mod = 998244353;

void solve(){
    int n;
    cin>>n;
    int arr[n-1];
    bool nmo=0;
    for(int i = 0; i<n-1; i++){
        cin>>arr[i];
        if(arr[i]==n-1) nmo=1;
    }
    vector<int>v;
    for(int i = 0; i<n; i++) v.push_back(i+1);
    int ans=0;
    do{
        bool fail=0;
        for(int i = 0; i<n-1; i++){
            int max1=0,max2=0;
            for(int j = 0; j<=i; j++) max1=max(max1,v[j]);
            for(int j = i+1; j<n; j++) max2=max(max2,v[j]);
            if(min(max1,max2)!=arr[i]){
                fail=1;
                break;
            }
        }
        if(!fail) ans++;
    }while(next_permutation(v.begin(),v.end()));
    cout<<ans<<"\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(ios::failbit);
    int t;
    cin>>t;
    while(t--) solve();
}