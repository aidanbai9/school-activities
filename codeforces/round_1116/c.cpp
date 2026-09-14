#include "bits/extc++.h"

using namespace std;

using ll = long long;

#define sz(x) int(std::size(x))

void solve(){
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    int a[2]={0,0};
    for(int i = 0; i<2*n; i++){
        if(s[i]=='1' && s[(i+1)%(2*n)]=='0'){
            a[i%2]++;
        }else{
            a[(i+1)%2]+=(s[i]=='1');
        }
    }
    cout<<a[0]<<" "<<a[1]<<"\n";
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
intuition: should always hold on until final minute?
- otherwise, u change difference by +2, but if other team waits
  until final minute they can change back
- if no other team (single 1) its like guarantee not guarantee
*/