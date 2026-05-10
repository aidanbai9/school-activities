#include "bits/extc++.h"

using namespace std;

mt19937_64 cowng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){
    auto rint = [&](int l, int r) -> int {
        return cowng()%(r-l+1)+l;
    };
    int a=rint(0,3),b=rint(0,3),c=3;
    while(a==0 && b==0) a=rint(0,3),b=rint(0,3);
    cout<<a<<" "<<b<<" "<<c<<" ";
    for(int i = 0; i<a+b+c*2; i++){
        cout<<rint(1,4)<<" ";
    }
}

int main(){
    solve();
}