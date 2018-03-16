#include <bits/stdc++.h>

using namespace std;
using namespace __gnu_cxx;

typedef double db;
typedef long long ll;
typedef pair<int,int> ii;

#define F        first
#define S        second
#define pnl      printf("\n")
#define sz(x)    (int)x.size()
#define sf(x)    scanf("%d",&x)
#define pf(x)    printf("%d\n",x)
#define all(x)   x.begin(),x.end()
#define rall(x)  x.rbegin(),x.rend()
#define FOR(a,b) for(int i = a; i < b; ++i)

const db eps = 1e-12;
const db pi = acos(-1);
const int inf = 0x3f3f3f3f;
const ll INF = inf * 2LL * inf;
const int mod = 1000 * 1000 * 1000 + 7;

int n, m;
char str[100005];
int op, cl, mxDif;
int dp[2020][2020][2][2];

int solve(int rem, int open, int close, int loc){
    if(close > open) return 0;
    int dif = abs(open - close);
    int flag = ((open >= close) ? 0 : 1);
    if(dif > 2000) return 0;
    if(rem == 0){
        if(loc == 1) return (dif == 0);
        if(open - close < mxDif) return 0;
        return solve(rem, open + op, close + cl, 1);
    }
    int &ret = dp[rem][dif][flag][loc];
    if(~ret) return ret;
    ret = 0;
    if(loc == 0){   // before s
        ret += solve(rem - 1, open + 1, close, 0);
        if(ret >= mod) ret-=mod;
        ret += solve(rem - 1, open, close + 1, 0);
        if(ret >= mod) ret-=mod;
        if(open - close >= mxDif){
            ret += solve(rem, open + op, close + cl, 1);
            if(ret >= mod) ret-=mod;
        }
    }else{          // after s
        ret += solve(rem - 1, open + 1, close, 1);
        if(ret >= mod) ret-=mod;
        ret += solve(rem - 1, open, close + 1, 1);
        if(ret >= mod) ret-=mod;
    }
    return ret;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);
#endif
    scanf("%d%d%s", &n, &m, str);
    for(int i = 0; str[i]; ++i){
        if(str[i] == '(') ++op;
        else ++cl;
        mxDif = max(mxDif, cl - op);
    }
    if(abs(op - cl) > n - m)
        return 0 * printf("%d\n", 0);
    memset(dp, -1, sizeof dp);
    printf("%d\n", solve(n - m, 0, 0, 0));
    return 0;
}