#include "bits/extc++.h"

using namespace std;

using ll = long long;

#define sz(x) int(std::size(x))

void solve(){
    int n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    int ln=0,rn=0,lm=0,rm=0;
    int pln=0,prn=0,plm=0,prm=0;
    int xp=0,yp=0;
    for(auto u: s){
        if(u=='U'){
            xp--;
        }else if(u=='D'){
            xp++;
        }else if(u=='R'){
            yp++;
        }else{
            yp--;
        }
        ln=min(ln,xp),rn=max(rn,xp),lm=min(lm,yp),rm=max(rm,yp);
        if(rn-ln+1>n || rm-lm+1>m){
            cout<<(1-pln)<<" "<<(1-plm)<<"\n";
            return;
        }
        pln=ln,prn=rn,plm=lm,prm=rm;
    }
    cout<<(1-ln)<<" "<<(1-lm)<<"\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(ios::failbit);
    int t;
    cin>>t;
    while(t--) solve();
}