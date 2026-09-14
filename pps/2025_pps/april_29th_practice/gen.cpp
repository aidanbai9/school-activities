#include "bits/extc++.h"

using namespace std;

using ll = long long;

#define sz(x) int(std::size(x))

mt19937_64 cowng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){
    auto rint = [&](int l, int r) -> int {
        return cowng()%(r-l+1)+l;
    };
    int n=rint(2,10),m=rint(n-1,min(n*(n-1)/2,n*2));
    cout<<n<<" "<<m<<"\n";
    set<pair<int,int>>edges;
    for(int i = 0; i<m; i++){
        if(i<n-1) edges.insert({i,i+1});
        else{
            int l=rint(0,n-1),r=rint(0,n-1);
            while(l==r || edges.count({l,r})) r=rint(0,n-1);
            edges.insert({l,r});
        }
    }
    vector<int>ord;
    for(int i = 0; i<n; i++){
        ord.push_back(i);
    }
    shuffle(ord.begin(),ord.end(),cowng);
    vector<pair<int,int>>vals;
    for(auto [a,b]: edges) vals.push_back({ord[a],ord[b]});
    shuffle(vals.begin(),vals.end(),cowng);
    for(auto [a,b]: vals) cout<<a+1<<" "<<b+1<<"\n";
    int k = rint(1,10);
    cout<<k<<"\n";
    for(int i = 0; i<k; i++){
        cout<<rint(1,n)<<" ";
    }
    cout<<"\n";
    int q = rint(1,min(6,k));
    cout<<q<<"\n";
    int prev=1;
    for(int i = 0; i<q; i++){
        prev=rint(prev,k-(q-i)+1);
        cout<<prev<<" ";
        prev++;
    }
    cout<<"\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(ios::failbit);
    int t=2;
    cout<<t<<"\n";
    while(t--) solve();
}