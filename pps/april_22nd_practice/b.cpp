#include "bits/extc++.h"

using namespace std;

void solve(){
    int n;
    string a;
    string b;
    cin>>n>>a>>b;
    int num01=0,num10=0;
    for(int i = 0; i<n; i++){
        if(a[i]=='0' && b[i]=='1') num01++;
        if(a[i]=='1' && b[i]=='0') num10++;
    }
    cout<<num01+num10-min(num01,num10)<<"\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(ios::failbit);
    int t;
    cin>>t;
    while(t--) solve();
}