#include "bits/extc++.h"

using namespace std;

#define sz(x) int(std::size(x))

constexpr int INF = 1e9+5;

mt19937_64 cowng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){
    auto rint = [&](int l, int r) -> int {
        return cowng()%(r-l+1)+l;
    };
    int n=rint(1,5),q=rint(1,5);
    cout<<n<<" "<<q<<"\n";
    int maxr=1e9;
    for(int i = 0; i<n; i++){
        cout<<rint(0,maxr)<<" "<<rint(0,maxr)<<" "<<rint(0,maxr)<<"\n";
    }
    for(int i = 0; i<q; i++){
        cout<<rint(0,maxr)<<" "<<rint(0,maxr)<<"\n";
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