#include "bits/extc++.h"

using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<array<int,4>>arr;
    for(int i = 0; i<n; i++){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        arr.push_back({a,b,c,d});
    }
    int minv=0;

    auto inr = [&](int l, int r, int val) -> bool {
        return (l<=val) && (val<=r);
    };
    int maxans=0;
    for(int i = 1; i<=n; i++){
        int cnum=0;
        for(int j = 0; j<n; j++){
            auto [a,b,c,d] = arr[j];
            if(!inr(a,b,cnum+1) && !inr(c,d,i-cnum)) cnum++;
        }
        if(cnum>=i) maxans=i;
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