#include "bits/extc++.h"

using namespace std;

using ll = long long;

vector<int>trs[2][2];

constexpr int maxn = 2e5+5;
constexpr ll mod = 998244353;

ll dp[2][2][maxn];
string val="01";

void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    for(int i = 0; i<=n; i++){
        for(int a = 0; a<2; a++){
            for(int b = 0; b<2; b++){
                dp[a][b][i]=0;
            }
        }
    }
    for(int a = 0; a<2; a++){
        if(s[n-2]!='?' && s[n-2]!=val[a]) continue;
        for(int b = 0; b<2; b++){
            if(s[n-1]!='?' && s[n-1]!=val[b]) continue;
            dp[a][b][n-2]++;
        }
    }
    for(int i = n-3; i>=0; i--){
        for(int a = 0; a<2; a++){
            if(s[i]!='?' && s[i]!=val[a]) continue;
            for(int b = 0; b<2; b++){
                if(s[i+1]!='?' && s[i+1]!=val[b]) continue;
                for(auto c: trs[a][b]){
                    dp[a][b][i]=(dp[a][b][i]+dp[b][c][i+1])%mod;
                }
            }
        }
    }
    ll sum=0;
    for(int a = 0; a<2; a++){
        for(int b = 0; b<2; b++){
            sum=(sum+dp[a][b][0])%mod;
        }
    }
    cout<<sum<<"\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(ios::failbit);
    for(int a = 0; a<2; a++){
    for(int b = 0; b<2; b++){
    for(int c = 0; c<2; c++){
        if(a+b != b+c) trs[a][b].push_back(c);
    }
    }
    }
    int t;
    cin>>t;
    while(t--) solve();
}
/*
thoughts section:
trivial dp?
dp[bit1][bit2][i] = for suffix i how many ways with a[i]=bit1, a[i+1]=bit2
dp[preset][anything][n-2]=1
transition:
if can set anything
dp[a][b][i]=sum dp[b][stuff that works][i+1]
else only transition to a=[preset]
*/