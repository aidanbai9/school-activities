#include "bits/extc++.h"

using namespace std;

using ll = long long;

#define sz(x) int(std::size(x))

bool isprime(int x){
    for(int i = 2; i<x; i++){
        if(x%i==0) return 0;
    }
    return 1;
}

void solve(){
    int n;
    cin>>n;
    if(isprime(n+1)) cout<<"YES\n";
    else cout<<"NO\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(ios::failbit);
    int t;
    cin>>t;
    while(t--) solve();
}