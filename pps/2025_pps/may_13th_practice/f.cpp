#include "bits/extc++.h"

using namespace std;

using ll = long long;

#define sz(x) int(std::size(x))

constexpr int maxn = 2005;

int n,m;
string grid[maxn];
int dp[maxn][maxn];
bool vis[maxn][maxn];

bool inb(int x, int y){
    return (0<=x) && (x<n) && (0<=y) && (y<m);
}

void dfs(int x, int y){
    if(vis[x][y]) return;
    vis[x][y]=1;
    int nx=x,ny=y;
    if(grid[x][y]=='U') nx--;
    if(grid[x][y]=='D') nx++;
    if(grid[x][y]=='L') ny--;
    if(grid[x][y]=='R') ny++;
    if(!inb(nx,ny)){
        dp[x][y]=0;
    }else{
        dfs(nx,ny);
        dp[x][y]=dp[nx][ny]+1;
    }
}

void solve(){
    cin>>n>>m;
    for(int i = 0; i<n; i++) cin>>grid[i];
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            dp[i][j]=0;
            vis[i][j]=0;
        }
    }
    int maxv=-1,xv,yv;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            dfs(i,j);
            if(dp[i][j]>maxv){
                maxv=dp[i][j];
                xv=i,yv=j;
            }
        }
    }
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<xv+1<<" "<<yv+1<<" "<<maxv+1<<"<<\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(ios::failbit);
    int t;
    cin>>t;
    while(t--) solve();
}