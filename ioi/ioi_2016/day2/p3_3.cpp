#include "bits/extc++.h"

using namespace std;

#define sz(x) int(std::size(x))

constexpr int maxn = 105;
int dp[maxn][maxn][maxn];


long long take_photos(int n, int m, int kv, std::vector<int> r, std::vector<int> c) {
    bool pos[m]{};
    for(auto u: r) pos[u]=1;
    for(int i = 0; i<=m; i++){
        for(int j = 0; j<=m; j++){
            for(int k = 0; k<=kv; k++) dp[i][j][k]=1e9;
        }
    }
    dp[0][0][0]=0;
    for(int i = 0; i<m; i++){
        for(int j = 0; j<=i; j++){
            for(int k = 0; k<=kv; k++){
                if(dp[i][j][k]==1e9) continue;
                if(j==0){
                    if(pos[i]==1){
                        dp[i+1][1][k+1]=min(dp[i+1][1][k+1],dp[i][j][k]);
                    }else{
                        dp[i+1][0][k]=min(dp[i+1][0][k],dp[i][j][k]);
                    }
                }else{
                    if(pos[i]==1){
                        dp[i+1][j+1][k]=min(dp[i+1][j+1][k],dp[i][j][k]);
                        dp[i+1][1][k+1]=min(dp[i+1][1][k+1],dp[i][j][k]+j*j);
                    }else{
                        dp[i+1][j+1][k]=min(dp[i+1][j+1][k],dp[i][j][k]);
                        dp[i+1][0][k]=min(dp[i+1][0][k],dp[i][j][k]+j*j);
                    }
                }
            }
        }
    }
    int minans=1e9;
    for(int i = 0; i<=kv; i++){
        for(int j = 0; j<=m; j++){
            if(dp[m][j][i]==1e9) continue;
            minans=min(minans,dp[m][j][i]+j*j);
        }
    }
    return minans;
    return 0;
}

int main() {
    int n, m, k;
    assert(3 == scanf("%d %d %d", &n, &m, &k));
    std::vector<int> r(n), c(n);
    for (int i = 0; i < n; i++) {
        assert(2 == scanf("%d %d", &r[i], &c[i]));
    }
    long long ans = take_photos(n, m, k, r, c);
    
    
    printf("%lld\n", ans);
    return 0;
}