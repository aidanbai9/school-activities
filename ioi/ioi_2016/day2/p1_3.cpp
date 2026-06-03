#include "bits/extc++.h"
#include "paint.h"

#include <cstdlib>

using namespace std;

#define sz(x) int(std::size(x))

constexpr int MAXK = 105;
constexpr int MAXN = 2e5+5;

bool dp[MAXK][MAXN];
bool dp2[MAXK][MAXN];

void initdp(string s, vector<int>c){
    int n=sz(s),k=sz(c);
    vector<int>psumb,psumw;
    psumb.push_back(0),psumw.push_back(0);
    for(int i = 0; i<n; i++){
        psumb.push_back(psumb.back()+(s[i]=='X'));
        psumw.push_back(psumw.back()+(s[i]=='_'));
    }
    auto allb = [&](int l, int r) -> bool {
        //can [l,r] be all black
        if(l<0 || r>=n) return 0;
        return (psumw[r+1]-psumw[l])==0;
    };
    auto allw = [&](int l, int r) -> bool {
        //can [l,r] be all white
        if(l<0 || r>=n) return 0;
        return (psumb[r+1]-psumb[l])==0;
    };
    for(int i = 0; i<=n; i++){
        dp[0][i]=allw(0,i-1);
    }
    for(int i = 1; i<=k; i++){
        for(int j = 1; j<=n; j++){
            if(s[j-1]=='.' || s[j-1]=='_'){
                dp[i][j]|=dp[i][j-1];
            }
            if(s[j-1]=='.' || s[j-1]=='X'){
                bool works=allb(j-c[i-1],j-1);
                if(j-c[i-1]<=0){
                    if(i!=1) works=0;
                }else{
                    if(!(allw(j-c[i-1]-1,j-c[i-1]-1) && dp[i-1][j-c[i-1]-1])) works=0;
                }
                dp[i][j]|=works;
            }

        }
    }
}

void initdp2(string s, vector<int>c){
    reverse(s.begin(),s.end());
    reverse(c.begin(),c.end());
    int n=sz(s),k=sz(c);
    vector<int>psumb,psumw;
    psumb.push_back(0),psumw.push_back(0);
    for(int i = 0; i<n; i++){
        psumb.push_back(psumb.back()+(s[i]=='X'));
        psumw.push_back(psumw.back()+(s[i]=='_'));
    }
    auto allb = [&](int l, int r) -> bool {
        //can [l,r] be all black
        if(l<0 || r>=n) return 0;
        return (psumw[r+1]-psumw[l])==0;
    };
    auto allw = [&](int l, int r) -> bool {
        //can [l,r] be all white
        if(l<0 || r>=n) return 0;
        return (psumb[r+1]-psumb[l])==0;
    };
    for(int i = 0; i<=n; i++){
        dp2[0][i]=allw(0,i-1);
    }
    for(int i = 1; i<=k; i++){
        for(int j = 1; j<=n; j++){
            if(s[j-1]=='.' || s[j-1]=='_'){
                dp2[i][j]|=dp2[i][j-1];
            }
            if(s[j-1]=='.' || s[j-1]=='X'){
                bool works=allb(j-c[i-1],j-1);
                if(j-c[i-1]<=0){
                    if(i!=1) works=0;
                }else{
                    if(!(allw(j-c[i-1]-1,j-c[i-1]-1) && dp2[i-1][j-c[i-1]-1])) works=0;
                }
                dp2[i][j]|=works;
            }

        }
    }
    for(int i = 0; i<(k+1)/2; i++){
        for(int j = 0; j<=n; j++){
            swap(dp2[i][j],dp2[k-i][j]);
        }
    }
    for(int i = 0; i<=k; i++){
        reverse(dp2[i],dp2[i]+(n+1));
    }
}

std::string solve_puzzle(std::string s, std::vector<int> c) {
    int n=sz(s),k=sz(c);
    vector<int>psumb,psumw;
    psumb.push_back(0),psumw.push_back(0);
    for(int i = 0; i<n; i++){
        psumb.push_back(psumb.back()+(s[i]=='X'));
        psumw.push_back(psumw.back()+(s[i]=='_'));
    }
    auto allb = [&](int l, int r) -> bool {
        //can [l,r] be all black
        if(l<0 || r>=n) return 0;
        return (psumw[r+1]-psumw[l])==0;
    };
    auto allw = [&](int l, int r) -> bool {
        //can [l,r] be all white
        if(l<0 || r>=n) return 0;
        return (psumb[r+1]-psumb[l])==0;
    };
    initdp(s,c);
    initdp2(s,c);
    int diff[n+1]{};
    auto updr = [&](int l, int r) -> void {
        diff[l]++,diff[r+1]--;
    };
    for(int i = 0; i<k; i++){
        for(int j = 0; j<=(n-c[i]); j++){
            if(((i==0 && j==0) || allw(j-1,j-1)) && ((i==k-1 && (j+c[i]==n)) || allw(j+c[i],j+c[i]))){
                if(((i==0 && j==0) || dp[i][j-1]) && ((i==k-1 && (j+c[i]==n)) || dp2[i+1][j+c[i]+1])){
                    if(allb(j,j+c[i]-1)) updr(j,j+c[i]-1);
                }
            }
        }
    }
    for(int i = 1; i<=n; i++){
        diff[i]+=diff[i-1];
    }
    string ans="";
    for(int i = 0; i<n; i++){
        if(s[i]!='.'){
            ans+=s[i];
            continue;
        }
        bool possw=0;
        for(int j = 0; j<=k; j++){
            possw|=(dp[j][i] && dp2[j][i+1]);
        }
        bool possb=(diff[i]!=0);
        if(possb && possw) ans+='?';
        else if(possb) ans+='X';
        else if(possw) ans+='_';
        //else assert(false);
    }
    return ans;
}

const int S_MAX_LEN = 200 * 1000;
char buf[S_MAX_LEN + 1];

int main() {
    assert(1 == scanf("%s", buf));
    std::string s = buf;
    int c_len;
    assert(1 == scanf("%d", &c_len));
    std::vector<int> c(c_len);
    for (int i = 0; i < c_len; i++) {
        assert(1 == scanf("%d", &c[i]));
    }
    std::string ans = solve_puzzle(s, c);


    printf("%s\n", ans.data());
    return 0;
}