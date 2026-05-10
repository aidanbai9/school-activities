#include "bits/extc++.h"

using namespace std;

using ll = long long;

using ull = unsigned long long;

ull Hash(ll x){
    ull val=x+0x9437832857387583;
    val=(val^(val>>30))*0x2375838572954737;
    val=(val^(val>>27))*0x2859237465682645;
    return val^(val>>31);
}

struct Fastmap {
    int n;
    vector<int>arr;
    vector<ll>val;
    vector<int>keys;
    Fastmap():n(1000003),arr(n,0),val(n,-1){};
    int idxv(ll x){
        ull hsh=Hash(x)%n;
        int cnt=0;
        while(val[hsh]!=-1 && val[hsh]!=x){
            cnt++;
            hsh=(hsh+cnt)%n;
        }
        if(val[hsh]==-1){
            keys.push_back(hsh);
            val[hsh]=x;
        }
        return hsh;
    }
    void setv(ll idx, ll val){
        int i=idxv(idx);
        arr[i]=val;
    }
    int getv(ll idx){
        return arr[idxv(idx)];
    }
    void clear(){
        for(auto u: keys){
            arr[u]=0,val[u]=-1;
        }
        keys.clear();
    }
};

void solve(){
    Fastmap mp;
    for(int i = 0; i<50; i++) mp.setv(i,i);
    for(int i = 0; i<50; i++) cout<<mp.getv(i)<<" ";
    cout<<"\n";
    mp.clear();
    for(int i = 0; i<50; i++) mp.setv(i,50-i);
    for(int i = 0; i<50; i++) cout<<mp.getv(i)<<" ";

}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(ios::failbit);
    solve();
}