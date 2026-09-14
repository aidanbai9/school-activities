#include "bits/extc++.h"

using namespace std;

using ll = long long;

#define sz(x) int(std::size(x))

#define int ll

template <typename T, typename ... U>
void dbgh(const T& t, const U&... u){
    cerr<<t;
    ((cerr<<" | "<<u),...);
    cerr<<"\n";
}
#ifdef DEBUG
#define dbg(...)\
cerr<<"L"<<__LINE__<<"["<<#__VA_ARGS__<<"]";\
dbgh(__VA_ARGS__)
#else
#define dbg(...)
#define cerr if(false)cerr
#endif

//destefano will cook for me and make sure this problem gets AC
//please speed i need this


void solve(){
    int n,q;
    cin>>n>>q;
    vector<int>arr(n);
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    vector<array<int,3>>quv;
    for(int i = 0; i<q; i++){
        int a,b,c;
        cin>>a>>b>>c;
        a--;
        quv.push_back({a,b,c});
    }
    ll ans[q];
    for(int i = 0; i<q; i++){
        ll ansv=0;
        ll cnt=0;
        auto [a,b,c] = quv[i];
        int idx=a;
        for(int i = 0; i<c; i++){
            cnt++;
            ansv+=ll(cnt)*(arr[idx]);
            idx+=b;
        }
        ans[i]=ansv;
    }
    for(int i = 0; i<q; i++){
        cout<<ans[i]<<" ";
    }
    cout<<"\n";
}

int32_t main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(ios::failbit);
    int t;
    cin>>t;
    while(t--) solve();
}