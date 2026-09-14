#include "bits/extc++.h"

using namespace std;

using ll = long long;

#define sz(x) int(std::size(x))

namespace __gnu_pbds {
template <typename T>
using ost = tree<T,null_type,std::less<T>,rb_tree_tag,tree_order_statistics_node_update>;
};

void solve(){
    int n,q;
    cin>>n>>q;
    int arr[n];
    for(int i = 0; i<n; i++) cin>>arr[i];
    set<array<int,3>>ranges;
    int pref[n]{};
    pref[0]=arr[0];
    for(int i = 1; i<n; i++){
        pref[i]=min(pref[i-1],arr[i]);
    }
    for(int i = 0; i<n; i++){
        int l=i;
        while(i<n && pref[i]==pref[l]){
            i++;
        }
        i--;
        ranges.insert({l,i,pref[i]});
    }
    while(q--){
        int idx,sub;
        cin>>idx>>sub;
        idx--;
        arr[idx]-=sub;
        int x=arr[idx];
        auto it = ranges.lower_bound({idx+1,-1,-1});
        it--;
        vector<array<int,3>>addv;
        vector<array<int,3>>delv;
        int lv=idx,rv=idx-1;
        auto [a,b,c]=(*it);
        cerr<<a<<" "<<b<<" "<<c<<"\n";
        if((*it)[0]==idx){
            if(it!=ranges.begin()){
                it--;
                if((*it)[2]==x){
                    lv=(*it)[0];
                }else{
                    it++;
                }
            }
        }
        if((*it)[2]==x){
            idx=(*it)[0];
            lv=idx;
        }
        while(it!=(ranges.end()) && (*it)[2]>=x){
            auto [l,r,val] = (*it);
            if(l<idx){
                addv.push_back({l,idx-1,val});
            }
            delv.push_back({l,r,val});
            rv=r;
            it++;
        }
        for(auto u: delv) ranges.erase(u);
        if(lv<=rv) ranges.insert({lv,rv,x});
        for(auto u: addv) ranges.insert(u);
        cout<<sz(ranges)<<" ";
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