#include "bits/extc++.h"

using namespace std;

void solve(){
    int a[3];
    cin>>a[0]>>a[1]>>a[2];
    sort(a,a+3);
    cout<<min(a[2]-a[0],a[1])<<"\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(ios::failbit);
    int t;
    cin>>t;
    while(t--) solve();
}
/*
thoughts section:
1. doing it on a+b becomes a,b,a+b
2. range of that is max(a,b)
3. range becomes second smallest element at least
4. second smallest element never decreases
    a. doesn't decrease if you choose it as a,b
    b. if you don't choose it it becomes either largest or largest+smallest
5. answer either current range or second smallest
*/