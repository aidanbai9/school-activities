#include "bits/extc++.h"

using namespace std;

using ll = long long;

#define sz(x) int(std::size(x))

void solve(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i<n; i++) cin>>arr[i];
    vector<pair<int,int>>runs;
    for(int i = 0; i<n; i++){
        int l=i;
        while(i<n && arr[i]==arr[l]) i++;
        i--;
        runs.push_back({arr[i],i-l+1});
    }
    int subv=0;
    auto checkv = [&](int idx, int val) -> bool {
        if(idx>=sz(runs) || idx<0) return 0;
        return runs[idx].first==val;
    };
    for(int i = 1; i<sz(runs); i++){
        int fv=runs[i-1].second,sv=runs[i].second;
        if(sv<fv) swap(sv,fv);
        if(sv==1 && fv==1) continue;
        if(runs[i-1].second==1 && checkv(i-2,runs[i].first)) continue;
        if(runs[i].second==1 && checkv(i+1,runs[i-1].first)) continue;
        if(fv==1) subv=max(subv,1);
        if(fv>1) subv=max(subv,2);
    }
    cout<<sz(runs)+subv<<"\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(ios::failbit);
    int t;
    cin>>t;
    while(t--) solve();
}