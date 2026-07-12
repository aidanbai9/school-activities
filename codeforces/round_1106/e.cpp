#include "bits/extc++.h"

using namespace std;

#define sz(x) int(std::size(x))

constexpr int maxn = 105;

bool dp[105][210][105];

void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    for(int i = 0; i<=n; i++){
        for(int j = 0; j<=2*n; j++){
            for(int k = 0; k<=n; k++) dp[i][j][k]=0;
        }
    }
    dp[0][0][0]=1;
    //store T-F
    //start when as large as possible
    int ans=1e9;

    auto updans = [&](int iv, int jv, int kv) -> void {
        int numt=iv-kv,numf=kv;
        ans=max(jv-105,ans);
    };

    for(int i = 0; i<n; i++){
        for(int j = 0; j<210; j++){
            for(int k = 0; k<=i; k++){
                if(!dp[i][j][k]) continue;
                //k is number F
                int numt=i-k;
                int cursum=numt-k;
                if(s[i]=='T'){
                    cursum++;
                    dp[i+1][max(j,cursum)][];

                }else if(s[i]=='F'){

                }else{

                }
            }
        }
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(ios::failbit);
    int t;
    cin>>t;
    while(t--) solve();
}