#include "bits/extc++.h"

using namespace std;

mt19937_64 cowng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){
    auto rint = [&](int l, int r) -> int {
        return cowng()%(r-l+1)+l;
    };
    int n=rint(1,10);
    cout<<n<<"\n";
    for(int i = 0; i<n; i++){
        cout<<rint(0,(n+i)/(i+1))<<" ";
    }
    cout<<"\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(ios::failbit);
    int t=2;
    cout<<t<<"\n";
    while(t--) solve();
}