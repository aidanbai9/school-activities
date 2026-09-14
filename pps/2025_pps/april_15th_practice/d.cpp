#include "bits/extc++.h"

using namespace std;

using ll = long long;

#define sz(x) int(std::size(x))

void solve(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i<n; i++) cin>>arr[i];
    vector<int>ev,ov;
    for(auto u: arr){
        if(u%2==0) ev.push_back(u);
        else ov.push_back(u);
    }
    sort(ev.begin(),ev.end());
    sort(ov.begin(),ov.end());
    ll diff=0;
    for(int i = 0; i<n; i++){
        if(i%2==0){
            //alice
            if(!ev.empty() && (ov.empty() || ev.back()>ov.back())){
                diff+=ev.back();
                ev.pop_back();
            }else{
                ov.pop_back();
            }
        }else{
            //bob
            if(!ev.empty() && (ov.empty() || ev.back()>ov.back())){
                ev.pop_back();
            }else{
                diff-=ov.back();
                ov.pop_back();
            }
        }
    }
    if(diff>0){
        cout<<"Alice\n";
    }else if(diff<0){
        cout<<"Bob\n";
    }else{
        cout<<"Tie\n";
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(ios::failbit);
    int t;
    cin>>t;
    while(t--) solve();
}