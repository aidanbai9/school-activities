#include "bits/extc++.h"

using namespace std;

using ll = long long;

#define sz(x) int(std::size(x))

void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>arr;
    bool vis[n]{};
    for(int i = 0; i<m; i++){
        int nv;
        cin>>nv;
        vector<int>vals(nv);
        for(int j = 0; j<nv; j++) cin>>vals[j];
        for(auto u: vals) vis[u]=1;
        for(int j = 0; j<sz(vals)-1; j++){
            if(vals[j]>vals[j+1]){
                cout<<"NO\n";
                return;
            }
        }
        arr.push_back(vals);
    }
    vector<int>failv;
    for(int i = 0; i<n; i++){ if(!vis[i]) failv.push_back(i); }
    reverse(failv.begin(),failv.end());
    vector<int>ord;
    for(auto u: arr) ord.push_back(u[0]);
    sort(arr.begin(),arr.end());
    for(auto &u: arr) reverse(u.begin(),u.end());
    vector<int>curf;
    for(auto &u: arr){
        curf.push_back(u.back());
        u.pop_back();
    }
    set<pair<int,int>>avail;
    auto tryadd = [&](int idx) -> void {
        if(idx<0) return;
        if(sz(arr[idx])==0) return;
        if(idx==m-1 || arr[idx].back()<curf[idx+1]){
            avail.insert({arr[idx].back(),idx});
        }
    };
    for(int i = 0; i<m; i++){
        if(sz(arr[i])==0) continue;
        tryadd(i);
    }
    while(!avail.empty()){
        while(sz(failv) && curf[0]>failv.back()){
            ord.push_back(failv.back());
            failv.pop_back();
        }
        auto it = avail.begin();
        auto [val,idx] = (*it);
        avail.erase(it);
        arr[idx].pop_back();
        ord.push_back(val);
        curf[idx]=val;
        tryadd(idx);
        tryadd(idx-1);
    }
    while(sz(failv) && curf[0]>failv.back()){
        ord.push_back(failv.back());
        failv.pop_back();
    }
    if(sz(failv)){
        cout<<"NO\n";
        return;
    }
    for(auto u: arr){
        if(sz(u)){
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";
    for(auto u: ord){
        cout<<u<<" ";
    }
    cout<<"\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(ios::failbit);
    solve();
}