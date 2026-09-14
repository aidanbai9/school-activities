#include "bits/extc++.h"

using namespace std;

#define sz(x) int(std::size(x))

void solve(){
    int n;
    cin>>n;
    if(n==1 || n==3){
        cout<<"-1\n";
        return;
    }
    for(int i = 0; i<n; i++){
        cout<<(i+n/2)%n+1<<" ";
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