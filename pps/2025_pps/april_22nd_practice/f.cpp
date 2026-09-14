#include "bits/extc++.h"

using namespace std;

using ll = long long;

#define sz(x) int(std::size(x))

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
    map<array<int,3>,vector<int>>idx;
    vector<pair<int,int>>qu[251];
    vector<array<int,3>>quv;
    bool visv[q]{};
    for(int i = 0; i<q; i++){
        int a,b,c;
        cin>>a>>b>>c;
        a--;
        idx[{a,b,c}].push_back(i);
        if(b<=250 && c>=350) qu[b].push_back({a,c});
        quv.push_back({a,b,c});
    }
    ll ans[q]{};
    ll cntval=0;
    for(int i = 1; i<=250; i++){
        ll psum[n+1]{},psum2[n+1]{};
        for(int j = 0; j<n; j++){
            psum[j+1]=arr[j];
            psum2[j+1]=ll(arr[j])*j;
            if(j+1-i>=0) psum[j+1]+=psum[j+1-i];
            if(j+1-i>=0) psum2[j+1]+=psum2[j+1-i];
        }
        auto rsum = [&](int l, int r) -> ll {
            return psum[r+1]-psum[max(0,l-i+1)];
        };
        auto rsumv = [&](int l, int r) -> ll {
            return psum2[r+1]-psum2[max(0,l-i+1)];
        };
        for(int u = 0; u<q; u++){
            auto [a,x,b] = quv[u];
            if(x!=i) continue;
            ll offs=(i-a)*rsum(a,a+(b-1)*i);
            ll sum=(rsumv(a,a+(b-1)*i)+offs)/i;
            cntval++;
            ans[u]=sum;
            visv[u]=1;
            assert(cntval<2e8);
        }
    }
    for(int i = 0; i<q; i++){
        ll ansv=0;
        ll cnt=0;
        auto [a,b,c] = quv[i];
        int idx=a;
        if(!visv[i]){
            for(int j = 0; j<c; j++){
                cnt++;
                ansv+=ll(cnt)*(arr[idx]);
                idx+=b;
                cntval++;
            }
            ans[i]=ansv;
        }
        assert(cntval<4e8);
    }
    for(int i = 0; i<q; i++){
        cout<<ans[i]<<" ";
    }
    cout<<"\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(ios::failbit);
    int t;
    cin>>t;
    while(t--) solve();
}