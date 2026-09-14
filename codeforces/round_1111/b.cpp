#include "bits/extc++.h"

using namespace std;

void solve(){
    int n,m,k;
    cin>>n>>k>>m;
    if(k>m){
        cout<<"NO\n";
        return;
    }
    cout<<"YES\n";
    int cnt=0;
    for(int i = 0; i<k-1; i++){
        cout<<"1 ";
        cnt++;
    }
    cout<<m-cnt<<" ";
    cnt++;
    for(; cnt<n; cnt++){
        cout<<"1 ";
    }
    cout<<"\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(ios::failbit);
    int t;
    cin>>t;
    while(t--) solve();
}