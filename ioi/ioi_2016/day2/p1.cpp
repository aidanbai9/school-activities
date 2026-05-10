#include "bits/extc++.h"
#include "paint.h"

#include <cstdlib>

using namespace std;

#define sz(x) int(std::size(x))

constexpr int maxn = 105;

bool dp[maxn][maxn];

bool poss(string &s, vector<int>&c){
    int n=sz(s);
    string val="";
    for(auto u: c){
        val+='_';
        for(int i = 0; i<u; i++){
            val+='X';
        }
    }
    for(int i = 0; i<=n; i++){
        for(int j = 0; j<=sz(val); j++) dp[i][j]=0;
    }
    dp[0][0]=1;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<sz(val); j++){
            if(!dp[i][j]) continue;
            if(j==(sz(val)-1)){
                if(s[i]!='X') dp[i+1][j]=1;
            }else{
                if(val[j]=='_'){
                    //doesn't have to to be exact
                    if(s[i]==val[j+1] || s[i]=='.'){
                        dp[i+1][j+1]=1;
                    }
                    if(s[i]!='X') dp[i+1][j]=1;
                }else{
                    //have to move on and be exact
                    if(s[i]==val[j+1] || s[i]=='.'){
                        dp[i+1][j+1]=1;
                    }
                }
            }
        }
    }
    return dp[n][sz(val)-1];
}

std::string solve_puzzle(std::string s, std::vector<int> c) {
    int n=sz(s),k=sz(c);
    string ans="";
    for(int i = 0; i<n; i++){
        if(s[i]!='.'){
            ans+=s[i];
            continue;
        }
        s[i]='X';
        bool poss1=poss(s,c);
        s[i]='_';
        bool poss0=poss(s,c);
        s[i]='.';
        if(poss1 && poss0) ans+='?';
        else if(poss1) ans+='X';
        else if(poss0) ans+='_';
        else assert(false);
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