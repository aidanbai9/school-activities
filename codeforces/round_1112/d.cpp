#include "bits/extc++.h"

using namespace std;

using ll = long long;

constexpr ll mod = 998244353;

void solve(){
    int n;
    cin>>n;
    int arr[n-1];
    bool nmo=0;
    for(int i = 0; i<n-1; i++){
        cin>>arr[i];
        if(arr[i]==n-1) nmo=1;
    }
    if(!nmo){
        cout<<"0\n";
        return;
    }
    int lval=0,rval=0;
    int l=0,r=n-2;
    int used=0;
    ll ans=1;
    while(true){
        if(arr[l]==n-1 && arr[r]==n-1){
            for(int i = l; i<=r; i++){
                if(arr[i]!=n-1){
                    ans=0;
                    break;
                }
            }
            for(int i = 1; i<=(r-l); i++){
                ans=(ans*i)%mod;
            }
            break;
        }
        if(arr[l]==arr[r]){
            ans=0;
            break;
        }
        if(arr[l]<arr[r]){
            if(arr[l]>lval){
                lval=arr[l];
                used++;
                l++;
            }else if(arr[l]<lval){
                ans=0;
                break;
            }else{
                if(used>=arr[l]){
                    ans=0;
                    break;
                }
                ans=(ans*(arr[l]-used))%mod;
                used++;
                l++;
            }
        }else{
            if(arr[r]>rval){
                rval=arr[r];
                used++;
                r--;
            }else if(arr[r]<rval){
                ans=0;
                break;
            }else{
                if(used>=arr[r]){
                    ans=0;
                    break;
                }
                ans=(ans*(arr[r]-used))%mod;
                used++;
                r--;
            }
        }
    }
    ans=(ans*2)%mod;
    cout<<ans<<"\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(ios::failbit);
    int t;
    cin>>t;
    while(t--) solve();
}