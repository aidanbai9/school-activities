#include "bits/extc++.h"

using namespace std;

using ll = long long;

#define sz(x) int(std::size(x))

void solve(){
    
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(ios::failbit);
    int t;
    cin>>t;
    while(t--) solve();
}
/*
thoughts section:
for each index just find the next value it switches for, then dp 

these pairs do not partially overlap 
(more explicitly if A<B and A stops at C>B, B must stop <=C)

for each i find smallest j such that sum[j]-sum[i-1]<arr[j]
sum[j]-arr[j]<sum[i-1]

*/