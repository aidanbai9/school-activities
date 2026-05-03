#include "bits/extc++.h"

using namespace std;

using ll = long long;

using i128 = __int128_t;

#define sz(x) int(std::size(x))

mt19937_64 cowng(chrono::steady_clock::now().time_since_epoch().count());

constexpr ll mod = 1e18+7;

ll query1(vector<int>arr, int qv){
    int n=sz(arr);
    auto rint = [&](ll l, ll r) -> ll {
        return cowng()%(r-l+1)+l;
    };
    vector<vector<int>>ele(n);
    for(int i = 0; i<n; i++){
        ele[arr[i]].push_back(i);
    }
    vector<ll>value(n);
    for(int a = 0; a<n; a++){
        auto b=ele[a];
        if(sz(b)==0) continue;
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
    return 1;
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
    vector<int>cnt(n,0),cnt2(n,0);
    int sz1=0,sz2=0;
    int lv=0,rv=0;
    ll sum=0;
    map<ll,int>pcnt;
    auto valv = [&](int idx) -> ll {
        return ((i128(psum[idx])*qv-i128(sum)*idx)%i128(mod)+mod)%mod;
    };
    auto addv = [&](int idx) -> void {
        pcnt[valv(idx)]++;
    };
    ll ans=0;
    for(int i = 0; i<n; i++){
        cnt[arr[i]]++;
        cnt2[arr[i]]++;
        if(cnt[arr[i]]==1){
            sz1++;
            sum=(sum+vals[arr[i]])%mod;
        }
        if(cnt2[arr[i]]==1){
            sz2++;
        }
        while(sz2>=qv){
            cnt2[arr[rv]]--;
            if(cnt2[arr[rv]]==0){
                sz2--;
            }
            addv(rv);
            rv++;
        }
        if(sz1>qv){
            while(sz1>qv){
                cnt[arr[lv]]--;
                if(cnt[arr[lv]]==0){
                    sz1--;
                    sum=(sum-vals[arr[lv]])%mod;
                }
                lv++;
            }
            pcnt.clear();
            for(int j = lv; j<rv; j++){
                addv(j);
            }
        }
        ans+=pcnt[valv(i+1)];
    }
    return ans;
    return 1;
}

void solve(){
    auto t1=chrono::steady_clock::now();
    int n,k;
    cin>>n>>k;
    vector<int>arr(n);
    for(int i = 0; i<n; i++){
        cin>>arr[i];
        arr[i]--;
    }
    vector<int>qu(k);
    for(int i = 0; i<k; i++) cin>>qu[i];
    for(int i = 0; i<k; i++){
        cout<<query1(arr,qu[i])<<" "<<query2(arr,qu[i])<<"\n";
    }
    auto t2=chrono::steady_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(t2-t1);
    //cout<<duration.count()<<"microseconds\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(ios::failbit);
    int t;
    cin>>t;
    while(t--) solve();
}