#include "bits/extc++.h"

using namespace std;

using ll = long long;

#define sz(x) int(std::size(x))

namespace __gnu_pbds {
template <typename T>
using ost = tree<T,null_type,std::less<T>,rb_tree_tag,tree_order_statistics_node_update>;
}
using __gnu_pbds::ost;

void solve(){
    int n;
    cin>>n;
    vector<array<int,3>>arr[n];
    map<array<int,3>,int>mp;
    for(int i = 0; i<n; i++){
        int a,b,c;
        cin>>a>>b>>c;
        arr[c-1].push_back({a,b,i});
        mp[{a,b,i}]=i;
    }
    ost<array<int,3>>lv,rv;
    for(int i = 0; i<n; i++){
        for(auto [a,b,c]: arr[i]){
            lv.insert({b,a,c});
            rv.insert({a,b,c});
        }
    }
    auto numl = [&](int l) -> int {
        return lv.order_of_key({l+1,-1,-1});  
    };
    auto numr = [&](int r) -> int {
        return sz(rv)-rv.order_of_key({r,-1,-1});
    };
    int ans[n]{};
    for(int i = 0; i<n; i++){
        for(auto [a,b,c]: arr[i]){
            lv.erase({b,a,c});
            rv.erase({a,b,c});
        }
        for(auto [a,b,c]: arr[i]){
            int ansv=1e9;
            int clv=numl(a),crv=numr(b);
            if(clv+crv!=sz(lv)) ansv=0;
            if(clv!=0){
                auto it = lv.find_by_order(clv-1);
                ansv=min(ansv,a-(*it)[0]);
            }
            if(crv!=0){
                auto it = rv.find_by_order(sz(rv)-crv);
                ansv=min(ansv,(*it)[0]-b);
            }
            ans[mp[{a,b,c}]]=ansv;
        }
        for(auto [a,b,c]: arr[i]){
            lv.insert({b,a,c});
            rv.insert({a,b,c});
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