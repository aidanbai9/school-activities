#include "bits/extc++.h"

using namespace std;

using ll = long long;

#define sz(x) int(std::size(x))

constexpr int maxn = 205;
vector<int>fac[maxn];

void solve(){
    int n;
    cin>>n;
    int succ[n];
    string s;
    cin>>s;
    for(int i = 0; i<n; i++){
        cin>>succ[i];
        succ[i]--;
    }
    bool vis[n]{};
    vector<ll>vals;
    for(int i = 0; i<n; i++){
        if(!vis[i]){
            vector<int>ele;
            vector<char>ch;
            int a=i;
            int b=i;
            do{
                ele.push_back(b);
                ch.push_back(s[b]);
                vis[b]=1;
                b=succ[b];
            }while(b!=a);
            for(auto u: fac[sz(ele)]){
                bool work=1;
                for(int j = 0; j<sz(ele); j++){
                    if(ch[(j+u)%sz(ele)]!=ch[j]){
                        work=0;
                        break;
                    }
                }
                if(work){
                    vals.push_back(u);
                    break;
                }
            }
        }
    }
    ll lcmv=1;
    for(auto u: vals) lcmv=lcm(lcmv,u);
    cout<<lcmv<<"\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(ios::failbit);
    for(int i = 1; i<maxn; i++){
        for(int j = 1; j<maxn; j++){
            if(i%j==0) fac[i].push_back(j);
        }
    }
    int t;
    cin>>t;
    while(t--) solve();
}