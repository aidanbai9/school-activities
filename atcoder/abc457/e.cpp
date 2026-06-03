#include "bits/extc++.h"

using namespace std;

using ll = __int128_t;

#define sz(x) int(std::size(x))

constexpr int maxn = 2e5+5;
int succ[20][maxn];

void solve(){
    int n,m;
    cin>>n>>m;
    map<pair<int,int>,int>cnt;
    vector<vector<int>>arr(n),rev(n);
    for(int i = 0; i<m; i++){
        int a,b;
        cin>>a>>b;
        a--,b--;
        arr[a].push_back(b);
        rev[b].push_back(a);
        cnt[{a,b}]++;
    }
    for(auto &b: arr) sort(b.begin(),b.end());
    for(auto &b: rev) sort(b.begin(),b.end());
    for(int i = 0; i<n; i++){
        succ[0][i]=1e9;
        if(sz(arr[i])!=0) succ[0][i]=arr[i][0];
    }
    for(int i = 1; i<20; i++){
        for(int j = 0; j<n; j++){
            succ[i][j]=min(succ[i-1][j],succ[i-1][min(n-1,j+(1<<(i-1)))]);
        }
    }
    auto minr = [&](int l, int r) -> int {
        if(r<l) return 1e9;
        int len=r-l+1;
        int lgv = __lg(len);
        return min(succ[lgv][l],succ[lgv][r-(1<<lgv)+1]);
    };
    int q;
    cin>>q;
    while(q--){
        int l,r;
        cin>>l>>r;
        l--,r--;
        int rv=n,lv=-1;
        auto it = upper_bound(arr[l].begin(),arr[l].end(),r);
        if(it!=arr[l].begin()){
            it--;
            lv=*it;
        }
        it = lower_bound(rev[r].begin(),rev[r].end(),l);
        if(it!=rev[r].end()){
            rv=*it;
        }
        if(lv!=r){
            if(lv>=rv-1){
                cout<<"Yes\n";
            }else{
                cout<<"No\n";
            }
        }else{
            if(cnt[{l,r}]>1){
                cout<<"Yes\n";
            }else{
                if(minr(l+1,r)<=r || minr(l,r-1)<=r-1){
                    cout<<"Yes\n";
                }else{
                    cout<<"No\n";
                }
            }
        }
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(ios::failbit);
    solve();
}