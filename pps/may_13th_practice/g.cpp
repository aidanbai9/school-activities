#include "bits/extc++.h"

using namespace std;

using ll = long long;

void solve(){
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>>arr;
    for(int i = 0; i<n; i++){
        int a,b;
        cin>>a>>b;
        arr.push_back({a,b});
    }
    vector<pair<int,int>>ranges;
    for(auto [a,b]: arr){
        int maxa=min(a,m),maxb=min(b,m);
        ranges.push_back({(a-maxa)-(b-(m-maxa)),(a-(m-maxb))-(b-maxb)});
    }
    ll sumv=0;
    for(auto [l,r]: ranges) sumv+=r;
    vector<pair<int,int>>ans;
    auto addr = [&](int a, int b, int val) -> void {
        //a+b=a+b-m
        //a-b=val
        int av=a-((a+b-m+val)/2);
        int bv=m-av;
        ans.push_back({av,bv});
    };
    for(int i= 0; i<n; i++){
        auto [a,b] = arr[i];
        auto [l,r] = ranges[i];
        if(sumv<=1){
            addr(a,b,r);
        }else{
            int cv=min(sumv,ll(r)-l);
            if(cv%2!=0) cv--;
            addr(a,b,r-cv);
            sumv-=cv;
        }
    }
    cout<<abs(sumv)<<"\n";
    for(auto [l,r]: ans){
        cout<<l<<" "<<r<<"\n";
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(ios::failbit);
    int t;
    cin>>t;
    while(t--) solve();
}