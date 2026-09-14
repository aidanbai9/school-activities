#include "bits/extc++.h"

using namespace std;

using ll = long long;

#define sz(x) int(std::size(x))

void solve(){
    int n;
    cin>>n;
    vector<array<int,3>>arr;
    map<int,vector<array<int,3>>>mp;
    for(int i = 0; i<n; i++){
        int a,b,c;
        cin>>a>>b>>c;
        arr.push_back({a,b,c});
    }
    //length is a+b-c
    //
    for(int i = 0; i<n; i++){
        auto [a,b,m] = arr[i];
        int maxa=min(a,m),maxb=min(b,m);
        int lv=(a-maxa)-(b-(m-maxa));
        int rv=(a-(m-maxb))-(b-maxb);
        mp[a+b-m].push_back({lv,rv,i});
    }
    int maxval=0,maxa=0,maxb=0;
    vector<pair<int,int>>ans(n);
    auto updans = [&](int x, int y) -> void {
        //a-b=y
        auto [a,b,c]=arr[x];
        //sum = a+b-c
        ll aval=(y+a+b-c)/2,bval=(a+b-c)-aval;
        ans[x]={a-aval,b-bval};
    };
    int ansv=0;
    for(auto [a,b]: mp){
        sort(b.begin(),b.end());
        vector<array<int,3>>vecs;
        int minr=1e9;
        for(auto [l,r,i]: b){
            minr=min(r,minr);
            if(minr<l){
                int rv=vecs.back()[0];
                for(auto [l,r,i]: vecs){
                    updans(i,rv);
                }
                ansv++;
                vecs.clear();
                minr=r;
            }
            vecs.push_back({l,r,i});
        }
        int rv=vecs.back()[0];
        for(auto [l,r,i]: vecs){
            updans(i,rv);
        }
        ansv++;
    }
    cout<<ansv<<"\n";
    for(auto [a,b]: ans){
        cout<<a<<" "<<b<<"\n";
        //assert(a>=0 && b>=0);
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(ios::failbit);
    int t;
    cin>>t;
    while(t--) solve();
}