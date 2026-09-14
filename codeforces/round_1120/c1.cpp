#include "bits/extc++.h"

using namespace std;

using ll = long long;

#define sz(x) int(std::size(x))

void solve(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i<n; i++) cin>>arr[i];
    int diff[n+1]{};
    auto rupd = [&](int l, int r) -> void {
        r=min(r,n-1);
        if(l>n-1) return;
        diff[l]++;
        diff[r+1]--;
    };
    for(int i = 0; i<n; i++){
        rupd((i+1)*arr[i],(i+1)*(arr[i]+1)-1);
    }
    int psum[n+1]{};
    psum[0]=diff[0];
    for(int i = 1; i<n; i++){
        psum[i]=psum[i-1]+diff[i];
    }
    vector<int>ans;
    for(int i = 0; i<n; i++){
        if(psum[i]==0) ans.push_back(i);
    }
    cout<<sz(ans)<<"\n";
    for(auto u: ans) cout<<u<<" ";
    cout<<"\n";
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
so for a_i=x
for all j<x, we need:
1. floor(S/i)=j to have a solution
2. floor(S/i)=x to have no solution
first condition tells us exists element in range [i*j,i*(j+1)-1]
second condition tells us does not exist element in range [i*x,i*(x+1)-1]
i think if we just include everything that isn't explicitly banned
since answer is guaranteed to exist it should just work.
*/