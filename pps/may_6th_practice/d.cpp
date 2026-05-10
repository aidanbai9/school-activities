#include "bits/extc++.h"

using namespace std;

void solve(){
    int n,k;
    cin>>n>>k;
    int psum[n+1]{};
    string s;
    cin>>s;
    for(int i = 0; i<n; i++){
        psum[i+1]=psum[i]+(s[i]=='W');
    }
    int minv=1e9;
    for(int i = 0; i<=n-k; i++){
        minv=min(minv,psum[i+k]-psum[i]);
    }
    cout<<minv<<"\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(ios::failbit);
    int t;
    cin>>t;
    while(t--) solve();
}