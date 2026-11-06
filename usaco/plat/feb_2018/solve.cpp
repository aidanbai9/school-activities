#include "bits/extc++.h"

using namespace std;

#define sz(x) int(std::size(x))

constexpr int INF = 1e9+5;

void solve(){
    int n,q;
    cin>>n>>q;
    vector<array<int,4>>sling,qu;
    for(int i = 0; i<n; i++){
        int x,y,c;
        cin>>x>>y>>c;
        sling.push_back({x,y,0,c});
    }
    for(int i = 0; i<q; i++){
        int a,b;
        cin>>a>>b;
        qu.push_back({a,b,1,0});
    }
    for(auto [a,b,c,d]: qu){
        int mind=abs(a-b);
        for(auto [x,y,val,dist]: sling){
            mind=min(mind,abs(a-x)+abs(b-y)+dist);
        }
        cout<<mind<<"\n";
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(ios::failbit);
#ifndef LOCAL
    freopen("slingshot.in","r",stdin);
    freopen("slingshot.out","w",stdout);
#endif
    solve();
}