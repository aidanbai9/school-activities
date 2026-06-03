#include "bits/extc++.h"

using namespace std;

mt19937_64 cowng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){
    auto rint = [&](int l, int r) -> int {
        return cowng()%(r-l+1)+l;  
    };
    int n=rint(1,10),m=rint(n,1e5);
    cout<<n<<" "<<m<<"\n";
    vector<int>arr;
    for(int i = 0; i<n; i++) arr.push_back(i);
    shuffle(arr.begin(),arr.end(),cowng);
    for(auto u: arr) cout<<u<<" ";
    cout<<"\n";
}

int main(){
    solve();
}