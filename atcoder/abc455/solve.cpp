#include "bits/extc++.h"

using namespace std;

using ll = long long;

#define sz(x) int(std::size(x))

mt19937_64 cowng(chrono::steady_clock::now().time_since_epoch().count());

constexpr ll mod = 1e9+7;

ll query1(vector<int>arr, int qv){
    //each element appears qv times
    int ans=0;
    int n=sz(arr);
    for(int i = 0; i<n; i++){
        map<int,int>cnt;
        auto check = [&]() -> bool {
            for(auto [a,b]: cnt){
                if(b!=qv) return 0;
            }
            return 1;
        };
        for(int j = i; j<n; j++){
            cnt[arr[j]]++;
            ans+=check();
        }
    }
    return ans;
}

ll query2(vector<int>arr, int qv){
    //qv distinct elements
    int ans=0;
    int n=sz(arr);
    for(int i = 0; i<n; i++){
        map<int,int>cnt;
        auto check = [&]() -> bool {
            if(sz(cnt)!=qv) return 0;
            int val=-1;
            for(auto [a,b]: cnt){
                if(val==-1) val=b;
                else if(b!=val) return 0;
            }
            return 1;
        };
        for(int j = i; j<n; j++){
            cnt[arr[j]]++;
            ans+=check();
        }
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