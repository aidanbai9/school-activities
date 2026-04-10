#include "bits/extc++.h"

using namespace std;

using ll = long long;

#define sz(x) int(std::size(x))

void solve(){
    int n;
    cin>>n;
    string s[n];
    vector<array<int,5>>arr;
    for(int i = 0; i<n; i++){
        cin>>s[i];
        int cnt[5]{};
        for(auto u: s[i]){
            cnt[u-'a']++;
        }
        arr.push_back({cnt[0],cnt[1],cnt[2],cnt[3],cnt[4]});
    }
    int maxans=0;
    for(int i = 0; i<5; i++){
        vector<int>cnt;
        for(auto x: arr){
            int sum=x[0]+x[1]+x[2]+x[3]+x[4];
            cnt.push_back(x[i]-(sum-x[i]));
        }
        sort(cnt.begin(),cnt.end());
        int ansv=0,sum=0;
        while(sz(cnt) && sum+cnt.back()>0){
            sum+=cnt.back();
            cnt.pop_back();
            ansv++;
        }
        maxans=max(maxans,ansv);
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