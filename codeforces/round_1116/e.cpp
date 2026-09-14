#include "bits/extc++.h"

using namespace std;

using ll = long long;

#define sz(x) int(std::size(x))

constexpr int maxn = 805;
string grid[maxn];

int modinv(int n, int b){
    for(int i = 1; i<n; i++){
        if(b*i % n == 1) return i;
    }
    assert(0);
}

int numb(int n){
    int val=0;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            val+=(grid[i][j]=='#');
        }
    }
    return val;
}
int bval;
int invval;

pair<int,int> calcsum(int n){
    int xp=0,yp=0;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            if(grid[i][j]=='#'){
                xp=(xp+i)%n;
                yp=(yp+j)%n;
            }
        }
    }
    return {(xp*invval)%n,(yp*invval)%n};
}

void solve1(){
    int n;
    cin>>n;
    for(int i = 0; i<n; i++) cin>>grid[i];
    bval=numb(n),invval=modinv(n,bval);
    pair<int,int>vals=calcsum(n);
    int c,d;
    cin>>c>>d;
    c--,d--;
    int dx=(c-vals.first+n)*bval,dy=(d-vals.second+n)*bval;
    dx%=n,dy%=n;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            if(grid[i][j]=='#'){
                if(grid[(i+dx)%n][(j+dy)%n]=='.'){
                    cout<<i+1<<" "<<j+1<<" ";
                    cout<<(i+dx)%n+1<<" "<<(j+dy)%n+1<<"\n";
                    return;
                }
            }
        }
    }
    if(dx==0 && dy==0){
        cout<<"1 1 1 1\n";
    }
}

void solve2(){
    int n;
    cin>>n;
    for(int i = 0; i<n; i++) cin>>grid[i];
    bval=numb(n),invval=modinv(n,bval);
    pair<int,int>vals=calcsum(n);
    cout<<vals.first+1<<" "<<vals.second+1<<"\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(ios::failbit);
    string s;
    cin>>s;
    if(s=="first"){
        int t;
        cin>>t;
        while(t--) solve1();
    }else{
        int t;
        cin>>t;
        while(t--) solve2();
    }
}
/*
thoughts section:
run twice :skull:
ok this is like... chessboard puzzle esque
gcd(n,w)=1 is a bit sus (like it has to be relevent)

ok genly i think
its just 
sum of x coordinates mod n
sum of y coordinates mod n

gcd(n,w)=1 comes in by ensuring that you can always swap stuff to make it work out

ok details:
calculate sum of x coord of black cells
calculate sum of y coord of black cells
say that gives (a,b)
say we want to encode (c,d)
gotta change by (c-a,d-b)
and basically this shift can't put black onto itself because
gcd(n,w)=1?

ok the issue is translations

multiply by mod inverse b?
*/