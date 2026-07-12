#include "bits/extc++.h"

using namespace std;

#define sz(x) int(std::size(x))

constexpr int maxn = 1e6+5;

bool comp[maxn];
vector<int>primes;
int spd[maxn];

void solve(){
    int n;
    cin>>n;
    map<int,int>fac;
    int x=n;
    while(x!=1){
        fac[spd[x]]++;
        x/=spd[x];
    }
    int ans=0;
    for(auto [a,b]: fac) ans+=b;
    ans+=sz(fac);
    ans--;
    cout<<ans<<"\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(ios::failbit);
    for(int i = 2; i<maxn; i++){
        if(!comp[i]){
            primes.push_back(i);
            spd[i]=i;
            for(int j = i*2; j<maxn; j+=i) spd[j]=i,comp[j]=1;
        }
    }
    int t;
    cin>>t;
    while(t--) solve();
}