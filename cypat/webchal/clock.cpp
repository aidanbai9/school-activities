#include "bits/extc++.h"

using namespace std;

using ll = long long;

#define X first
#define Y second

constexpr ll mod = 24767;

pair<ll,ll> add(pair<ll,ll>a, pair<ll,ll>b){
    return {((a.X*b.X-a.Y*b.Y)%mod+mod)%mod, ((a.X*b.Y+a.Y*b.X)%mod+mod)%mod};
}

int main(){
    pair<ll,ll>g = {17317,4255};
    pair<ll,ll>a=g;
    for(int i = 0; i<2158; i++){
        a=add(a,g);
    }
    cout<<a.X<<" "<<a.Y<<"\n";
}