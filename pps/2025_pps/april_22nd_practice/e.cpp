#include "bits/extc++.h"

using namespace std;

void solve(){
    int n,m,xa,ya,xb,yb;
    cin>>n>>m>>xa>>ya>>xb>>yb;
    if(xa>xb){
        cout<<"Draw\n";
        return;
    }
    auto canmv = [&](int a, int b, int num, bool alice) -> bool {
        //can move a to b in num steps
        if(b<a){
            if(alice) a--;
            b-=num,a-=num;
            b=max(b,1),a=max(a,1);
            return (a==b);
        }
        if(alice && a<b) a++;
        a+=num,b+=num;
        a=min(m,a),b=min(m,b);
        return (a==b);
    };
    if(xa%2==xb%2){
        //bob has chance of winning
        int mv=(xb-xa)/2;
        if(canmv(yb,ya,mv,0)) cout<<"Bob\n";
        else cout<<"Draw\n";
    }else{
        //alice has chance of winning
        int mv=(xb-xa)/2;
        if(canmv(ya,yb,mv,1)) cout<<"Alice\n";
        else cout<<"Draw\n";
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(ios::failbit);
    int t;
    cin>>t;
    while(t--) solve();
}