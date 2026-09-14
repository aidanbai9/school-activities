#include "bits/extc++.h"

using namespace std;

using ll = long long;

#define sz(x) int(std::size(x))

constexpr int maxn = 2005;

int dp[maxn][maxn];
// position i, currently j things in position, minimum deleted
// 3 things matter... position, how many deleted, how many in position
// and the intuition is u want to minimize amount deleted to achieve some number in position
// so its like if ur in a certain position, u have some amount deleted, u obviously want max in position...


void solve(){
    int n,k;
    cin>>n>>k;
    vector<int>arr;
    for(int i = 0; i<n; i++){
        int x;
        cin>>x;
        arr.push_back(i-(x-1));
    }
    for(int i = 0; i<=n; i++){
        for(int j = 0; j<=n; j++){
            dp[i][j]=-1;
        }
    }
    dp[0][0]=0;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            if(dp[i][j]==-1) continue;
            dp[i+1][j]=max(dp[i+1][j],dp[i][j]+(arr[i]==j));
            dp[i+1][j+1]=max(dp[i+1][j+1],dp[i][j]);
        }
    }
    for(int j = 0; j<=n; j++){
        if(dp[n][j]>=k){
            cout<<j<<"\n";
            return;
        }
    }
    cout<<"-1\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(ios::failbit);
    int t;
    cin>>t;
    while(t--) solve();
}