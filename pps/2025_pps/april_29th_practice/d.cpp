#include "bits/extc++.h"

using namespace std;

#define sz(x) int(std::size(x))

int n,ans;
bool poss=1;
vector<int>vals;

void dfs(int l, int r, int ql, int qr){
    if(l==r){
        return;
    }
    int mid = (l+r)/2, midr=(ql+qr)/2;
    int cnt=0;
    for(int i = l; i<=mid; i++){
        cnt+=(vals[i]<=midr);
    }
    if(!(cnt==0 || cnt==(mid-l+1))){
        poss=0;
        return;
    }
    if(cnt==0){
        ans++;
        dfs(mid+1,r,ql,midr);
        dfs(l,mid,midr+1,qr);
    }else{
        dfs(l,mid,ql,midr);
        dfs(mid+1,r,midr+1,qr);
    }
}

void solve(){
    cin>>n;
    vals.clear();
    for(int i = 0; i<n; i++){
        int x;
        cin>>x;
        x--;
        vals.push_back(x);
    }
    poss=1,ans=0;
    dfs(0,n-1,0,n-1);
    if(!poss){
        cout<<"-1\n";
        return;
    }
    cout<<ans<<"\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(ios::failbit);
    int t;
    cin>>t;
    while(t--) solve();
}