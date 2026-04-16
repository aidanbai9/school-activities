#include "bits/extc++.h"

using namespace std;

using ll = long long;

#define sz(x) int(std::size(x))

void solve(){
    int n;
    cin>>n;
    vector<array<int,3>>forw,rev;
    for(int i = 0; i<n; i++){
        int a,b;
        cin>>a>>b;
        forw.push_back({a,b,i});
        rev.push_back({b,a,i});
    }
    sort(forw.rbegin(),forw.rend());
    sort(rev.rbegin(),rev.rend());
    int ans[n];
    for(int i = 0; i<n; i++) ans[i]=-1;
    pair<int,int>minf={2e9,-1},minr={2e9,-1};
    vector<array<int,3>>arr=forw;
    for(int id = n-1; id>=0; id--){
        auto [a,b,i] = arr[id];
        while(sz(forw) && forw.back()[0]<a){
            minf=min(minf,{forw.back()[1],forw.back()[2]});
            forw.pop_back();
        }
        while(sz(rev) && rev.back()[0]<a){
            minr=min(minr,{rev.back()[1],rev.back()[2]});
            rev.pop_back();
        }
        if(minf.first<b){
            ans[i]=minf.second;
        }
        if(minr.first<b){
            ans[i]=minr.second;
        }
    }
    for(int i = 0; i<n; i++){
        if(ans[i]==-1){
            cout<<"-1 ";
            continue;
        }
        cout<<ans[i]+1<<" ";
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