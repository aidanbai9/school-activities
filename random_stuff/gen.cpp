#include "bits/extc++.h"

using namespace std;

int main(){
    int n=99999;
    cout<<n<<"\n";
    int num=0;
    for(int i = 0; i<n/3; i++){
        cout<<num<<" "<<num+i<<" "<<num+2*i<<" ";
        num+=30000;
    }
}