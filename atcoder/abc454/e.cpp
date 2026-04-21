#include <bits/stdc++.h>

using namespace std;

string ans="";

void solvev(int n, int m, int a, int b){
    if(n!=2){
        if(a<n-2){
            solvev(n-2,m,a,b);
            ans+='D';
            ans=ans+string(m-1,'L');
            ans+='D';
            ans=ans+string(m-1,'R');
        }else{
            ans=ans+string(m-1,'R');
            ans+='D';
            ans=ans+string(m-1,'L');
            ans+='D';
            solvev(n-2,m,a-2,b);
        }
        return;
    }
    if(m!=2){
        if(b<m-2){
            solvev(n,m-2,a,b);
            ans=ans+"RURD";
        }else{
            ans=ans+"DRUR";
            solvev(n,m-2,a,b-2);
        }
        return;
    }
    if(a==1){
        ans=ans+"RD";
    }else{
        ans=ans+"DR";
    }
}

void solve(){
    int n,a,b;
    cin>>n>>a>>b;
    a--,b--;
    if(n%2==1){
        cout<<"No\n";
        return;
    }
    if((a+b)%2!=1){
        cout<<"No\n";
        return;
    }
    cout<<"Yes\n";
    ans="";
    solvev(n,n,a,b);
    cout<<ans<<"\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(ios::failbit);
    int t;
    cin>>t;
    while(t--) solve();
}