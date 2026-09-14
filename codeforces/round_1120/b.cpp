#include "bits/extc++.h"

using namespace std;

using ll = long long;

#define sz(x) int(std::size(x))

constexpr int maxn = 1005;

int arr[maxn][maxn];

void solve(){
    int n,k;
    cin>>n>>k;
    if(k<n || k>=2*n){ cout<<"-1\n"; return; }
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++) arr[i][j]=0;
    }
    int val = 2*n-1-k;
    for(int i = 0; i<n; i++){
        if(i<val){
            arr[n-i-1][i]=n*n-i;
        }else{
            arr[0][i]=n*n-i;
        }
    }
    for(int i = n; i<2*n-1; i++){
        arr[i-(n-1)][n-1]=n*n-i;
    }
    int cnt=0;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            if(arr[i][j]==0){
                cnt++;
                arr[i][j]=cnt;
            }
        }
    }
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cout<<n*n+1-arr[i][j]<<" ";
        }
        cout<<"\n";
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(ios::failbit);
    int t;
    cin>>t;
    while(t--) solve();
}
/*
thoughts section:
not possible if k<n or k>=2n
construction for 2n-1 is just line the max values on the edges
decrease by 1 just like move stuff into into the diagonal
*/