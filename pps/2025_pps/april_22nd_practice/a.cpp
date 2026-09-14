#include "bits/extc++.h"

using namespace std;

using ll = long long;

void solve(){
    int x1,y1,x2,y2;
    int x3,y3,x4,y4;
    cin>>x1>>y1>>x2>>y2;
    cin>>x3>>y3>>x4>>y4;
    int minx=min({x1,x2,x3,x4});
    int maxx=max({x1,x2,x3,x4});
    cout<<(maxx-minx)*(maxx-minx)<<"\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(ios::failbit);
    int t;
    cin>>t;
    while(t--) solve();
}