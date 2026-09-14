#include "bits/extc++.h"

using namespace std;

using ll = long long;

#define sz(x) int(std::size(x))

constexpr int maxn = 5e5+5;
int dp[3][maxn];
bool bl[2][maxn];

vector<pair<int,int>> cprs(vector<pair<int,int>>arr){
    set<int>vals;
    for(auto [a,b]: arr) vals.insert(a);
    vector<int>pos;
    for(auto u: vals) pos.push_back(u);
    map<int,int>mp;
    for(int i = 0; i<sz(pos)-1; i++){
        int dif=pos[i+1]-pos[i];
        dif=(dif+1)%2+1;
        mp[pos[i+1]]=pos[i]+dif;
        pos[i+1]=pos[i]+dif;
    }
    for(auto &[a,b]: arr){
        if(mp.count(a)) a=mp[a];
    }
    return arr;
}

void solve(){
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>>arr;
    for(int i = 0; i<m; i++){
        int a,b;
        cin>>a>>b;
        a--,b--;
        arr.push_back({b,a});
    }
    arr.push_back({-1,0});
    arr.push_back({-1,1});
    arr.push_back({n,0});
    arr.push_back({n,1});
    sort(arr.begin(),arr.end());
    arr=cprs(arr);
    int maxv=arr.back().first;
    for(int i = 0; i<=maxv+5; i++){
        dp[0][i]=0,dp[1][i]=0,dp[2][i]=0;
        bl[0][i]=0,bl[1][i]=0;
    }
    for(auto [a,b]: arr){
        if(a!=-1)
        bl[b][a]=1;
    }
    dp[0][0]=1;
    for(int i = 0; i<=maxv; i++){
        if(dp[0][i]){
            if(bl[0][i]==bl[1][i]){
                dp[0][i+1]=1;
            }
            if(bl[1][i]){
                dp[1][i]=1;
            }
            if(bl[0][i]){
                dp[2][i]=1;
            }
        }
        if(dp[1][i]){
            if(!bl[0][i] && !bl[0][i+1]){
                dp[2][i+1]=1;
            }
            if(bl[0][i]){
                dp[0][i+1]=1;
            }
        }
        if(dp[2][i]){
            if(!bl[1][i] && !bl[1][i+1]){
                dp[1][i+1]=1;
            }
            if(bl[1][i]){
                dp[0][i+1]=1;
            }
        }
        //1 = (-1,0), 2 = (0,-1)
    }
    if(dp[0][maxv]){
        cout<<"Yes\n";
    }else{
        cout<<"No\n";
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(ios::failbit);
    int t;
    cin>>t;
    while(t--) solve();
}