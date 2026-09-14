#include "bits/extc++.h"

using namespace std;

using ll = long long;

#define sz(x) int(std::size(x))

constexpr int mod = 1e9+7;

bool on(int i, int j){
    return i&(1<<j);
}

void solve(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i<n; i++) cin>>arr[i];
    int ans=0;
    for(int m = 0; m<(1<<n); m++){
        bool fail=0;
        for(int i = 1; i<=n; i++){
            for(int j = 0; j<min(n,arr[i-1]*i); j+=i){
                bool good=0;
                for(int k = j; k<min(j+i,n); k++){
                    if(on(m,k)){good=1; break;}
                }
                if(!good){ fail=1; break;}
            }
            for(int k = arr[i-1]*i; k<min(n,arr[i-1]*i+i); k++){
                if(on(m,k)){fail=1; break;}
            }
            if(fail) break;
        }
        if(!fail){
            ans++;
            for(int i = 0; i<n; i++){
                cerr<<on(m,i);
            }
            cerr<<"\n";
        }
    }
    cout<<ans<<"\n";
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
so for a_i=x
for all j<x, we need:
1. floor(S/i)=j to have a solution
2. floor(S/i)=x to have no solution
first condition tells us exists element in range [i*j,i*(j+1)-1]
second condition tells us does not exist element in range [i*x,i*(x+1)-1]
so there are only n logn ranges we care about

dp on something
ok we are given second conditions don't drown out first conditions

dp on prefix we mainly would need to know when something is forced
but that seems hard...

prefix + last used would be enough...
dp[i] = if use i what is ans for prefix

dp[i] = sum j=ending of range from last cycle to i-1 dp[j]
*/