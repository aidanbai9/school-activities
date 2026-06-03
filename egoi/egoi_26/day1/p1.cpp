#include "bits/extc++.h"

using namespace std;

void solve(){
    int n;
    string s;
    cin>>n>>s;
    if(s[0]!='+' || s.back()!='-'){
        cout<<"NO\n";
        return;
    }
    vector<int>nump,numn;
    for(int i = 0; i<n; i++){
        if(s[i]=='+') nump.push_back(i);
        else numn.push_back(i);
    }
    reverse(numn.begin(),numn.end());
    cout<<"YES\n";
    for(auto u: nump) cout<<u<<" ";
    for(auto u: numn) cout<<u<<" ";
    cout<<"\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(ios::failbit);
    solve();
}