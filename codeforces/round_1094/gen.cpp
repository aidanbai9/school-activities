#include "bits/extc++.h"

using namespace std;

using ll = long long;

#define sz(x) int(std::size(x))

mt19937_64 cowng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){
    auto rint = [&](int l, int r) -> int {
        return cowng()%(r-l+1)+l;
    };
    int n=50000,m=100000,q=rint(2,n);
    cout<<n<<" "<<m<<" "<<q<<"\n";
    for(int i = 0; i<m; i++){
        int a=rint(1,n),b=rint(1,n),c=rint(1,m);
        cout<<a<<" "<<b<<" "<<c<<"\n";
    }
    for(int i = 0; i<q; i++){
        cout<<rint(1,n)<<" ";
    }
    cout<<"\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(ios::failbit);
    int t=2;
    cout<<t<<"\n";
    while(t--){
        solve();
    }
}