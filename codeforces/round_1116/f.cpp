#include "bits/extc++.h"

using namespace std;

using ll = long long;

#define sz(x) int(std::size(x))

void solve(){

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
i mean its always like ~logn to get everything to 1
it feels optimal to just always apply it on max?
ok the main thing is sus stuff happens when everything is 1

as in if everything is 1 u need # 1's to win

also like every number will become 1 at some point

so i think if an element is already at 1, optimal to "take as many elements down with it"
(i.e. if something is at one just clear it immediately)

ok this heuristic is actually like choose min element each time not max

also stuff at like 111111_2 is sus because divide by 2 doesn't decrease length


*/