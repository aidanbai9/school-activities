#include "bits/extc++.h"

using namespace std;

using ll = long long;

#define sz(x) int(std::size(x))

mt19937_64 cowng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){
    auto rint = [&](int l, int r) -> int {
        return cowng()%(r-l+1)+l;
    };
    int n=200000,k=10;
    cout<<n<<" "<<k<<"\n";
    for(int i = 0; i<n; i++) cout<<rint(1,n)<<" ";
    cout<<"\n";
    for(int i = 0; i<k; i++) cout<<rint(1,n)<<" ";
    cout<<"\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(ios::failbit);
    int t=1;
    cout<<t<<"\n";
    while(t--) solve();
}