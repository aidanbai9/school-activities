#include "bits/extc++.h"

using namespace std;

using ll = long long;

#define sz(x) int(std::size(x))

constexpr int mod = 1e9+7;

void solve(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i<n; i++) cin>>arr[i];
    int fail[n+1]{};
    {
        int diff[n+1]{};
        auto rupd = [&](int l, int r) -> void {
            r=min(r,n-1);
            if(l>n-1) return;
            diff[l]++;
            diff[r+1]--;
        };
        for(int i = 0; i<n; i++){
            rupd((i+1)*arr[i],(i+1)*(arr[i]+1)-1);
        }
        fail[0]=diff[0];
        for(int i = 1; i<n; i++){
            fail[i]=fail[i-1]+diff[i];
        }
    }
    vector<pair<int,int>>evnts[n];
    set<pair<int,int>>vals;
    vector<int>curv(n,-1);
    for(int i = 0; i<n; i++) vals.insert({curv[i],i});
    int endv=-1;
    for(int i = 0; i<n; i++){
        for(int j = 1; j<=arr[i]; j++){
            if(j*(i+1)>=n) continue;
            evnts[j*(i+1)].push_back({i+1,0});
        }
        endv=max(endv,(arr[i]-1)*(i+1));
    }
    ll dp[n+1]{};
    dp[0]=1;
    ll psum[n+2]{};
    psum[1]=1; 
    auto dpsum = [&](int l, int r) -> ll {
        if(l>r) return 0;
        return (psum[r+1]-psum[l]+mod)%mod;
    };
    auto updv = [&](int a, int b) -> void {
        vals.erase({curv[a],a});
        curv[a]=b;
        vals.insert({curv[a],a});
    };
    for(int i = 1; i<=n; i++){
        for(auto [a,b]: evnts[i-1]){
            if(b==0){
                updv(a,max(i-1-a,0));
            }
        }
        if(fail[i-1]){
            psum[i+1]=psum[i];
            continue;
        }
        if(vals.empty()){
            dp[i]=(dp[i-1]*2)%mod;
        }else{
            auto it = --vals.end();
            dp[i]=dpsum((*it).first+1,i-1);
        }
        psum[i+1]=(psum[i]+dp[i])%mod;
    }
    ll ans = dpsum(endv+1,n);
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