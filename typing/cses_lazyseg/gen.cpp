#include "bits/extc++.h"

using namespace std;

mt19937_64 cowng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){
    auto rint = [&](int l, int r) -> int {
        return cowng()%(r-l+1)+l;
    };
    int n=rint(1,3),q=rint(1,3);
    cout<<n<<" "<<q<<"\n";
    for(int i = 0; i<n; i++){
        cout<<rint(1,5)<<" ";
    }
    cout<<"\n";
    while(q--){
        int t=rint(1,3);
        int l=rint(1,n),r=rint(1,n);
        if(r<l) swap(l,r);
        cout<<t<<" "<<l<<" "<<r<<" ";
        if(t<3){
            cout<<rint(1,5)<<" ";
        }
        cout<<"\n";
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(ios::failbit);
    solve();
}