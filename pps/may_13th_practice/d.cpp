#include "bits/extc++.h"

using namespace std;

using ll = long long;

#define sz(x) int(std::size(x))

void solve(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i<n; i++) cin>>arr[i];
    string s;
    cin>>s;
    vector<int>a,b;
    for(int i = 0; i<n; i++){
        if(s[i]=='B'){
            a.push_back(arr[i]);
        }else{
            b.push_back(arr[i]);
        }
    }
    sort(a.begin(),a.end());
    sort(b.rbegin(),b.rend());
    for(int i = 1; i<=sz(a); i++){
        if(a[i-1]<i){
            cout<<"NO\n";
            return;
        }
    }
    for(int i = 0; i<sz(b); i++){
        if(b[i]>n-i){
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(ios::failbit);
    int t;
    cin>>t;
    while(t--) solve();
}