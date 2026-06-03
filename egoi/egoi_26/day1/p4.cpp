#include "bits/extc++.h"

using namespace std;

using ll = long long;

#define sz(x) int(std::size(x))

constexpr int maxn = 1e5+5;

ll readv(ll pos){
    cout<<"r "<<pos<<"\n";
    int x;
    cin>>x;
    return x;
}

void writv(ll pos, ll val){
    cout<<"w "<<pos<<" "<<val<<"\n";
}

void ansv(int x){
    cout<<"! "<<x<<"\n";
}

void solve(){
    int idx,m;
    cin>>idx>>m;
    set<int>vis;
    vis.insert(idx);
    writv(idx,1);
    bool anot=0;
    for(int i = 0; i<20; i++){
        if(readv(idx^1)){
            anot=1;
            int val=idx^1;
            while(val>=4){
                val/=2;
            }
            writv(val^1,1);
        }else{
            idx/=2;
            vis.insert(idx);
            writv(idx,1);
        }
    }
    for(int i = 0; i<5; i++){
        if(!vis.count(i))
    }
    if(anot) ansv(2);
    else ansv(1);
}

int main(){
    cin.exceptions(ios::failbit);
    solve();
}