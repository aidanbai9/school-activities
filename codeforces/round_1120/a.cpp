#include "bits/extc++.h"

using namespace std;

using ll = long long;

#define sz(x) int(std::size(x))

void solve(){
    int n;
    cin>>n;
    int arr[n];
    int cnt=0;
    for(int i = 0; i<n; i++){
        cin>>arr[i];
        cnt+=(arr[i]==0);
    }
    if(cnt<=n/2){
        cout<<"Bessie\n";
    }else{
        cout<<"Elsie\n";
    }
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
bessie wants to decrease # of 0's
elsie wants to decrease # of 1's
pretty sure its just is # 0's larger than number turns bessie gets
*/