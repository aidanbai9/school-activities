#include "bits/extc++.h"

using namespace std;

using ll = long long;

#define sz(x) int(std::size(x))

void solve(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i<n; i++) cin>>arr[i];
    int score[n]{};
    int maxans=0;
    for(int i = n-1; i>=0; i--){
        score[i]=arr[i];
        if(i+arr[i]<n) score[i]+=score[i+arr[i]];
        maxans=max(maxans,score[i]);
    }
    cout<<maxans<<"\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(ios::failbit);
    int t;
    cin>>t;
    while(t--) solve();
}