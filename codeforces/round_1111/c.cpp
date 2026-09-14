#include "bits/extc++.h"

using namespace std;

void solve(){
    int n;
    cin>>n;
    int arr[n],brr[n];
    for(int i = 0; i<n; i++) cin>>arr[i];
    for(int i = 0; i<n; i++) cin>>brr[i];
    int num00=0,num01=0,num10=0,num11=0;
    for(int i = 0; i<n; i++){
        if(arr[i]==0 && brr[i]==0) num00++;
        if(arr[i]==0 && brr[i]==1) num01++;
        if(arr[i]==1 && brr[i]==0) num10++;
        if(arr[i]==1 && brr[i]==1) num11++;
    }
    if(num10+num01==0){
        cout<<"0\n";
        return;
    }else if(num10%2==1){
        cout<<"1\n";
        return;
    }else if(num10!=0){
        cout<<"2\n";
        return;
    }else if(num00!=0 && num11!=0){
        cout<<"2\n";
        return;
    }
    cout<<"-1\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(ios::failbit);
    int t;
    cin>>t;
    while(t--) solve();
}