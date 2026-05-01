#include "bits/extc++.h"

using namespace std;

using ld = long double;

ld dp[36][1000];

void solve(){
    int n;
    cin>>n;
    memset(dp,0,sizeof(dp));
    dp[0][0]=1;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<36; j++){
            for(int k = 1; k<=6; k++){
                for(int l = 1; l<=6; l++){
                    dp[(j+k+l)%36][i+1]+=dp[j][i];
                }
            }
        }
        //normalize
        ld sum=0;
        for(int j = 0; j<36; j++) sum+=dp[j][i+1];
        for(int j = 0; j<36; j++){
            dp[j][i+1]/=sum;
        }
    }
    for(int i = 0; i<36; i++){
        cout<<"at cell "<<i<<" with probability: "<<dp[i][n]<<"\n";
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(ios::failbit);
    solve();
}