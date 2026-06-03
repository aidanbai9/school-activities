#include "bits/extc++.h"

using namespace std;

#define sz(x) int(std::size(x))

void solve(){
    string a,b;
    cin>>a>>b;
    map<char,int>mp;
    for(int i = 0; i<26; i++) mp[a[i]]=i;
    int sum=0;
    for(int i = 0; i<sz(b)-1; i++) sum+=abs(mp[b[i]]-mp[b[i+1]]);
    cout<<sum<<"\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(ios::failbit);
    int t;
    cin>>t;
    while(t--) solve();
}