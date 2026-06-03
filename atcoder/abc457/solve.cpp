#include "bits/extc++.h"

using namespace std;

using ll = long long;

#define sz(x) int(std::size(x))

void solve(){
    ll n,kv;
    cin>>n>>kv;
    vector<pair<ll,ll>>vals;
    for(int i = 0; i<n; i++){
        ll x;
        cin>>x;
        vals.push_back({x,i+1});
    }
    sort(vals.begin(),vals.end());
    for(int i = 0; i<kv; i++){
        vals[0].first+=vals[0].second;
        sort(vals.begin(),vals.end());
    }
    cout<<vals[0].first<<"\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(ios::failbit);
    solve();
}