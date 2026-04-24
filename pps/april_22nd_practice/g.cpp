#include "bits/extc++.h"

using namespace std;

using ll = long long;

#define sz(x) int(std::size(x))

template <typename T, typename ... U>
void dbgh(const T& t, const U&... u){
    cerr<<t;
    ((cerr<<" | "<<u),...);
    cerr<<"\n";
}
#ifdef DEBUG
#define dbg(...)\
cerr<<"L"<<__LINE__<<"["<<#__VA_ARGS__<<"]";\
dbgh(__VA_ARGS__)
#else
#define dbg(...)
#define cerr if(false)cerr
#endif

//destefano will cook for me and make sure this problem gets AC
//please speed i need this

constexpr int maxn = 1e5+5;
int n,m,k;
string grid[maxn];

bool val(int x, int y){
    return (grid[x][y]=='#');
}

int sv(){
    vector<vector<int>>psumR(n,vector<int>(m+1,0));
    vector<vector<int>>psumC(m,vector<int>(n+1,0));
    vector<vector<int>>diagsum(n+m,vector<int>(1,0));
    vector<vector<int>>idxv(n,vector<int>(m,0));
    vector<vector<int>>sumv(n,vector<int>(m,0));
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            psumR[i][j+1]=psumR[i][j]+val(i,j);
        }
    }
    for(int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            psumC[i][j+1]=psumC[i][j]+val(j,i);
        }
    }
    for(int i = 0; i<n+m-1; i++){
        int px=i,py=0;
        if(px>=n){
            px=n-1,py=i-px;
        }
        while(px>=0 && py<m){
            idxv[px][py]=sz(diagsum[i])-1;
            diagsum[i].push_back(diagsum[i].back()+val(px,py));
            px--,py++;
        }
    }
    auto rows = [&](int rv, int l, int r) -> ll {
        return psumR[rv][r+1]-psumR[rv][l];
    };
    auto cols = [&](int cv, int l, int r) -> ll {
        return psumC[cv][r+1]-psumC[cv][l];
    };
    auto diag = [&](int x, int y) -> ll {
        if(x+y>=n+m-1) return 0;
        int sum=x+y;
        int ex=x-k,ey=sum-ex;
        if(ex<0) ex=0,ey=sum-ex;
        if(x>=n) x=n-1,y=sum-x;
        if(ey>=m) ey=m-1,ex=sum-ey;
        //dbg(ex,ey,x,y);
        //cerr<<sz(diagsum[sum])<<" "<<idxv[ex][ey]+1<<" "<<idxv[x][y]<<"\n";
        return diagsum[sum][idxv[ex][ey]+1]-diagsum[sum][idxv[x][y]];
    };
    for(int i = 0; i<=min(n-1,k); i++){
        sumv[0][0]+=rows(i,0,min(m-1,k-i));
    }

    for(int i = 1; i<n; i++){
        ll subv=rows(i-1,0,min(m-1,k));
        ll addv=diag(i+k,0);
        //dbg(i,addv);
        sumv[i][0]=sumv[i-1][0]-subv+addv;
    }
    for(int i = 0; i<n; i++){
        for(int j = 1; j<m; j++){
            ll subv=cols(j-1,i,min(n-1,i+k));
            //dbg(i+k,j);
            ll addv=diag(i+k,j);
            sumv[i][j]=sumv[i][j-1]-subv+addv;
        }
    }
    /*for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cout<<sumv[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n";*/
    int maxv=0;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++) maxv=max(maxv,sumv[i][j]);
    }
    return maxv;
}

void solve(){
    cin>>n>>m>>k;
    //cout<<n<<" "<<m<<"\n";
    for(int i = 0; i<n; i++){
        cin>>grid[i];
    }
    int ans=sv();
    for(int i = 0; i<n/2; i++){
        swap(grid[i],grid[n-1-i]);
    }
    ans=max(ans,sv());
    for(int i = 0; i<n; i++) reverse(grid[i].begin(),grid[i].end());
    ans=max(ans,sv());
    for(int i = 0; i<n/2; i++){
        swap(grid[i],grid[n-1-i]);
    }
    ans=max(ans,sv());
    cout<<ans<<"\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(ios::failbit);
    int t;
    cin>>t;
    while(t--) solve();
}