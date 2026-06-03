#include "bits/extc++.h"

using namespace std;

mt19937_64 cowng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){
    auto rint = [&](int l, int r) -> int {
        return (cowng()%(r-l+1)+l);
    };
    int n=rint(1,5);
    cout<<n<<"\n";
    for(int i = 0; i<n; i++){
        int a=rint(0,5),b=rint(0,5),m=rint(0,a+b);
        cout<<a<<" "<<b<<" "<<m<<"\n";
    }
}

int main(){
    int t=2;
    cout<<t<<"\n";
    while(t--) solve();
}