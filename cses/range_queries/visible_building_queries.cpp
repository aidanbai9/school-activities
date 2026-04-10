#include "bits/extc++.h"

using namespace std;

void solve(){
    int n,q;
    cin>>n>>q;
    int arr[n];
    for(int i = 0; i<n; i++) cin>>arr[i];
    map<pair<int,int>,vector<int>>mp;
    map<int,vector<int>>qu;
    for(int i = 0; i<q; i++){
        int l,r;
        cin>>l>>r;
        l--,r--;
        qu[l].push_back(r);
        mp[{l,r}].push_back(i);
    }
    for(auto &[a,b]: qu){
        sort(b.begin(),b.end());
        b.erase(unique(b.begin(),b.end()),b.end());
    }
    deque<int>pref;
    int ans[q]{};
    for(int i = n-1; i>=0; i--){
        while(!pref.empty() && arr[pref[0]]<=arr[i]){
            pref.pop_front();
        }
        pref.push_front(i);
        for(auto u: qu[i]){
            
        }
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(ios::failbit);
    solve();
}