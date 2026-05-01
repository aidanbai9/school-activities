#include "bits/extc++.h"

using namespace std;

using ll = long long;

#define sz(x) int(std::size(x))

mt19937_64 cowng(chrono::steady_clock::now().time_since_epoch().count());

constexpr ll mod = 1e9+7;

ll query1(vector<int>arr, int qv){
    int n=sz(arr);
    auto rint = [&](ll l, ll r) -> ll {
        return cowng()%(r-l+1)+l;
    };
    map<int,vector<int>>ele;
    for(int i = 0; i<n; i++){
        ele[arr[i]].push_back(i);
    }
    vector<ll>value(n);
    for(auto [a,b]: ele){
        ll sumv=0;
        vector<ll>hsh;
        for(int i = 0; i<min(sz(b),qv-1); i++){
            ll val=rint(0,mod-1);
            hsh.push_back(val);
            sumv=(sumv+val)%mod;
        }
        hsh.push_back((mod-sumv)%mod);
        for(int i = 0; i<sz(b); i++){
            value[b[i]]=hsh[i%qv];
        }
    }
    vector<ll>psum;
    psum.push_back(0);
    for(auto u: value) psum.push_back((psum.back()+u)%mod);
    vector<int>cnt(n);
    int lv=0;
    map<ll,int>pcnt;
    ll ans=0;
    pcnt[0]=1;
    for(int i = 0; i<n; i++){
        cnt[arr[i]]++;
        if(cnt[arr[i]]==qv+1){
            while(cnt[arr[i]]==qv+1){
                cnt[arr[lv]]--;
                pcnt[psum[lv]]--;
                lv++;
            }
        }
        ans+=pcnt[psum[i+1]];
        pcnt[psum[i+1]]++;
    }
    return ans;
}

ll query2(vector<int>arr, int qv){
    //qv distinct elements
    int n=sz(arr);
    auto rint = [&](ll l, ll r) -> ll {
        return cowng()%(r-l+1)+l;
    };
    map<int,ll>vals;
    for(auto u: arr){
        vals[u]=rint(0,mod-1);
    }
    vector<ll>psum;
    psum.push_back(0);
    for(int i = 0; i<n; i++){
        psum.push_back((psum.back()+vals[arr[i]])%mod);
    }
    map<ll,int>pcnt;
    int lv=0,rv=0;
    map<int,int>cnt,cntv;
    ll val=0,ans=0;
    auto cval = [&](int idx) -> ll {
        return (qv)*psum[idx+1]-val*idx;
    };
    cout<<"\n";
    for(int i = 0; i<n; i++){
        cnt[arr[i]]++;
        cout<<i<<" "<<sz(cnt)<<"\n";
        if(cnt[arr[i]]==1) val=(val+vals[arr[i]])%mod;
        cout<<i<<" "<<sz(cnt)<<"\n";
        if(sz(cnt)>qv){
            pcnt.clear();
            while(sz(cnt)>qv){
                cnt[arr[lv]]--;
                if(lv<rv) cntv[arr[lv]]--;
                if(cnt[arr[lv]]==0){
                    cnt.erase(arr[lv]);
                    val=(val-vals[arr[i]])%mod;
                }
                lv++;
            }
            rv=lv;
        }
        while(cntv[arr[rv]]<cnt[arr[rv]]){
            pcnt[cval(rv)]++;
            cntv[arr[rv]]++;
            rv++;
        }
        if(cnt[arr[rv]]==0) cnt.erase(arr[rv]);
        cout<<sz(cnt)<<" "<<qv<<" "<<i<<" "<<lv<<" "<<rv<<"\n";
        ans+=pcnt[i];
    }
    return ans;
}

void solve(){
    int n,k;
    cin>>n>>k;
    vector<int>arr(n);
    for(int i = 0; i<n; i++) cin>>arr[i];
    vector<int>qu(k);
    for(int i = 0; i<k; i++) cin>>qu[i];
    for(int i = 0; i<k; i++){
        cout<<query1(arr,qu[i])<<" "<<query2(arr,qu[i])<<"\n";
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(ios::failbit);
    int t;
    cin>>t;
    while(t--) solve();
}