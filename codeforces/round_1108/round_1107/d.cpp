#include "bits/extc++.h"

using namespace std;

using ll = long long;

constexpr int maxn = 1e5+50;

int mvs[maxn];
int numz[maxn];
int ov[maxn];
int dp[16][maxn],dp2[16][maxn];

void solve(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i<n; i++) cin>>arr[i];
    int minans=1e9;
    for(int i = 0; i<n; i++){
        vector<pair<int,int>>vals;
        for(int j = 0; j<=15; j++){
            int val=arr[i]+j;
            vals.push_back({numz[val],mvs[ov[val]]+j});
        }
        for(int j = 0; j<=15; j++){
            dp[j][i]=1e9,dp2[j][i]=1e9;
            for(auto [a,b]: vals){
                if(a==j) dp[j][i]=min(dp[j][i],b);
                if(a==j) dp2[j][i]=min(dp2[j][i],b);
            }
            if(j!=0) dp[j][i]=min(dp[j][i],dp[j-1][i]);
        }
    }
    for(int i = 0; i<=15; i++){
        int ans=0;
        for(int j = 0; j<n; j++){
            ans+=dp[i][j];
        }
        for(int j = 0; j<n; j++){
            minans=min(minans,ans-dp[i][j]+dp2[i][j]+i);
        }
    }
    cout<<minans<<"\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(ios::failbit);
    for(int i = 1; i<maxn; i++){
        if(i%2==0){
            mvs[i]=mvs[i/2]+1;
            numz[i]=numz[i/2]+1;
            ov[i]=ov[i/2];
        }else{
            mvs[i]=mvs[i-1]+1;
            numz[i]=0;
            ov[i]=i;
        }
    }
    int t;
    cin>>t;
    while(t--) solve();
}