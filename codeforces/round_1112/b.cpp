#include "bits/extc++.h"

using namespace std;

void solve(){
    int n,k;
    cin>>n>>k;
    if(k<0 || k>n-2){
        cout<<"-1\n";
        return;
    }
    int a=k/2,b=k-a;
    int left=n;
    for(int i = 0; i<a+1; i++){
        cout<<"0";
        left--;
    }
    for(int i = 0; i<b+1; i++){
        cout<<"1";
        left--;
    }
    for(int i = 0; i<left; i++){
        cout<<i%2;
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