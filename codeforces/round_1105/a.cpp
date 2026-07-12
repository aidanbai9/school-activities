#include "bits/extc++.h"

using namespace std;

int dp[1000][1000];

void solve(){
    for(int k = 1; k<1000; k++){
        for(int n = 0; n<1000; n++){
            for(int i = 0; i<10; i++){
                if((n-((1<<i)-1)>=0)){
                    dp[k][n]=max(dp[k][n],dp[k-1][n-((1<<i)-1)]+i);
                }
            }
        }
    }
    for(int i = 0; i<20; i++){
        for(int j = i; j<=20; j++){
            cout<<i<<" "<<j<<": "<<dp[i][j]<<"\n";
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