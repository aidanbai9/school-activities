#include "bits/extc++.h"

using namespace std;

#define sz(x) int(std::size(x))

constexpr int maxn = 1005;
int dp[2][maxn][maxn];


long long take_photos(int n, int m, int kv, std::vector<int> r, std::vector<int> c) {
    bool pos[m]{};
    for(auto u: r) pos[u]=1;
    for(int i = 0; i<=m; i++){
        for(int j = 0; j<=m; j++){
            for(int k = 0; k<=kv; k++) dp[0][j][k]=1e9,dp[1][j][k]=1e9;
        }
    }
    dp[0][0][0]=0;
    for(int i = 0; i<m; i++){
        for(int j = 0; j<=i; j++){
            for(int k = 0; k<=kv; k++){
                if(dp[i%2][j][k]==1e9) continue;
                if(j==0){
                    if(pos[i]==1){
                        dp[(i+1)%2][1][k+1]=min(dp[(i+1)%2][1][k+1],dp[i%2][j][k]);
                    }else{
                        dp[(i+1)%2][0][k]=min(dp[(i+1)%2][0][k],dp[i%2][j][k]);
                    }
                }else{
                    if(pos[i]==1){
                        dp[(i+1)%2][j+1][k]=min(dp[(i+1)%2][j+1][k],dp[i%2][j][k]);
                        dp[(i+1)%2][1][k+1]=min(dp[(i+1)%2][1][k+1],dp[i%2][j][k]+j*j);
                    }else{
                        dp[(i+1)%2][j+1][k]=min(dp[(i+1)%2][j+1][k],dp[i%2][j][k]);
                        dp[(i+1)%2][0][k]=min(dp[(i+1)%2][0][k],dp[i%2][j][k]+j*j);
                    }
                }
                dp[i%2][j][k]=1e9;
            }
        }

    }
    int minans=1e9;
    for(int i = 0; i<=kv; i++){
        for(int j = 0; j<=m; j++){
            if(dp[m%2][j][i]==1e9) continue;
            minans=min(minans,dp[m%2][j][i]+j*j);
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