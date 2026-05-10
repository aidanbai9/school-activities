#include "bits/extc++.h"

using namespace std;

#define sz(x) int(std::size(x))

constexpr int maxn = 105;
bool cov[maxn][maxn];

long long take_photos(int n, int m, int k, std::vector<int> r, std::vector<int> c) {
    auto fill_square = [&](int x, int y) -> void {
        int lv=min(x,y),rv=max(x,y);
        for(int i = lv; i<=rv; i++){
            for(int j = lv; j<=rv; j++){
                cov[i][j]=1;
            }
        }
    };
    for(int i = 0; i<n; i++){
        fill_square(r[i],c[i]);
    }
    int ans=0;
    for(int i = 0; i<m; i++){
        for(int j = 0; j<m; j++){
            ans+=cov[i][j];
        }
    }
    return ans;
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