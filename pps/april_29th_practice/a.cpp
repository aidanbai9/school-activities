#include "bits/extc++.h"

using namespace std;

#define sz(x) int(std::size(x))

void solve(){
    string a,b;
    cin>>a>>b;
    if(a==b){
        cout<<"=\n";
        return;
    }
    map<char,int>rnk;
    rnk['S']=0;
    rnk['M']=1;
    rnk['L']=2;
    if(rnk[a.back()]>rnk[b.back()]){
        cout<<">\n";
        return;
    }
    if(rnk[a.back()]<rnk[b.back()]){
        cout<<"<\n";
        return;
    }
    if(a.back()=='L'){
        cout<<"<>"[sz(a)>sz(b)]<<"\n";
        return;
    }
    cout<<"><"[sz(a)>sz(b)]<<"\n";
    return;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(ios::failbit);
    int t;
    cin>>t;
    while(t--) solve();
}