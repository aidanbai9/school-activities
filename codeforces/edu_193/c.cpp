#include "bits/extc++.h"

using namespace std;

using ll = long long;

#define sz(x) int(std::size(x))

constexpr int maxn = 2e5+5;

bool visa[maxn],visb[maxn];

ll msum(int x, int y, vector<int>arr, vector<int>brr){
    int n=sz(arr),m=sz(brr);
    int lapcnt=0;
    ll maxsum=0;
    ll sum=0;
    int ux=0;
    for(int i = 0; i<min(n,x); i++){
        visa[arr[i]]=1;
        sum+=arr[i];
        ux++;
    }
    int uv=0;
    int yv=0;
    for(int i = 0; i<m; i++){
        if(uv>=y) continue;
        if(visa[brr[i]]){ lapcnt++; continue; }
        visb[brr[i]]=1;
        useb.push_back(brr[i]);
        sum+=brr[i];
        uv++;
        yv=i+1;
    }
    maxsum=sum;
    for(int i = x; i<n; i++){
        if(lapcnt==0) continue;
        if(uv>=y) continue; 
        lapcnt--;
        sum+=arr[i];
        uv++;
        if(visb[arr[i]]){
            sum-=arr[i];
            if(yv!=m){
                sum+=brr[yv];
                visb[brr[yv]]=1;
                yv++;
            }
        }
        maxsum=max(maxsum,sum);
    }

    for(auto u: arr) visa[u]=0;
    for(auto u: brr) visb[u]=0;
    return maxsum;
}

void solve(){
    int x,y;
    cin>>x>>y;
    int n,m;
    cin>>n>>m;
    ll maxsum=0;
    
    vector<int>arr(n),brr(m);
    for(int i = 0; i<n; i++) cin>>arr[i];
    for(int j = 0; j<m; j++) cin>>brr[j];
    reverse(arr.begin(),arr.end());
    reverse(brr.begin(),brr.end());
    maxsum=max(msum(x-1,y,arr,brr),msum(x,y-1,arr,brr));
    cout<<maxsum<<"\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(ios::failbit);
    int t;
    cin>>t;
    while(t--) solve();
}