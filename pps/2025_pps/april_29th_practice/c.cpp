#include "bits/extc++.h"

using namespace std;

#define sz(x) int(std::size(x))

void solve(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i<n; i++) cin>>arr[i];
    int minans=n;
    for(int i = 0; i<n; i++){
        int sum=0;
        for(int j = 0; j<=i; j++) sum+=arr[j];
        int maxseg=i+1;
        bool fail=0;
        for(int j = i+1; j<n; j++){
            int sumv=0;
            int lv=j;
            while(j<n && sumv<sum){
                sumv+=arr[j];
                j++;
            }
            maxseg=max(maxseg,j-lv);
            j--;
            if(sumv!=sum) fail=1;
        }
        if(!fail) minans=min(minans,maxseg);
    }
    cout<<minans<<"\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(ios::failbit);
    int t;
    cin>>t;
    while(t--) solve();
}