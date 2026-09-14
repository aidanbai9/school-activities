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

mt19937_64 cowng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){
    auto rint = [&](ll l, ll r) -> ll {
        return cowng()%(r-l+1)+l;
    };
    int n=50000,q=100000;
    cout<<n<<" "<<q<<"\n";
    for(int i = 0; i<n; i++){
        cout<<rint(1,10)<<" ";
    }
    cout<<"\n";
    while(q--){
        int st=rint(1,n);
        int b=rint(1,n),k=rint(1,n);
        while(st+b*(k-1)>n) {
            b=rint(1,n),k=rint(1,n);
        }
        cout<<st<<" "<<b<<" "<<k<<"\n";
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(ios::failbit);
    int t=2;
    cout<<t<<"\n";
    while(t--) solve();
}