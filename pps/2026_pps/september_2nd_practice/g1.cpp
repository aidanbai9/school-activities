#include "bits/extc++.h"

using namespace std;

#define sz(x) int(std::size(x))

using ll = long long;

int query(int x){
    cout<<"+ "<<x<<"\n";
    int val;
    cin>>val;
    return val;
}

void answer(int x){
    cout<<"! "<<x<<"\n";
}

mt19937_64 cowng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){
    auto rint = [&](ll l, ll r) -> ll {
        return cowng()%(r-l+1)+l;
    };
    int x;
    cin>>x;
    int maxv=x;
    int quv=1000;
    int xv=100,yv=(quv-xv)/2;
    for(int i = 0; i<xv-5; i++){
        int val=query(rint(1,ll(1e9)));
        maxv=max(maxv,val);
    }
    vector<int>vals;
    vector<int>weight;
    for(int i = 0; i<yv; i++){
        int val=query(yv);
        vals.push_back(val);
        weight.push_back(yv);
    }
    {
        int val=query(maxv);
        vals.push_back(val);
        weight.push_back(maxv);
    }
    for(int i = 0; i<yv; i++){
        int val=query(1);
        vals.push_back(val);
        weight.push_back(1);
    }
    for(int i = sz(vals)-1; i>=0; i--){
        for(int j = sz(vals)-1; j>i; j--){
            if(vals[i]==vals[j]){
                int sum=0;
                for(int k = i+1; k<=j; k++){
                    sum+=weight[k];
                }
                answer(sum);
                return;
            }
        }
    }
}

int main(){
    cin.exceptions(ios::failbit);
    solve();
}