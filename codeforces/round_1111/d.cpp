#include "bits/extc++.h"

using namespace std;

void solve(){
    int n,q;
    cin>>n>>q;//q = 0 for now
    int arr[n],brr[n];
    for(int i = 0; i<n; i++){cin>>arr[i]; brr[i]=arr[i];}
    sort(brr,brr+n);

    int r=0;
    auto check = [&](int x) -> bool {
        if((1<<x)>=n) return 1;
        for(int i = 0; i<n; i+=(1<<x)){
            int fval=brr[min(n-1,i+(1<<x)-1)];
            for(int j = i; j<min(n,(i+(1<<x))); j++){
                if(arr[j]>fval) return 0;
                if(arr[j]<brr[i]) return 0;
            }
        }
        return 1;
    };
    for(; r<21; r++){
        if(check(r)) break;
    }
    cout<<(1<<r)/2<<"\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(ios::failbit);
    int t;
    cin>>t;
    while(t--) solve();
}