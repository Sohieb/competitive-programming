#include <bits/stdc++.h>

using namespace std;
using namespace __gnu_cxx;

typedef double db;
typedef long long ll;
typedef pair<db, db> pdd;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef unsigned long long ull;

#define F          first
#define S          second
#define pnl        printf("\n")
#define sz(x)      (int)x.size()
#define sf(x)      scanf("%d",&x)
#define pf(x)      printf("%d\n",x)
#define all(x)     x.begin(),x.end()
#define rall(x)    x.rbegin(),x.rend()
#define rep(i, n)  for(int i = 0; i < n; ++i)

const db eps = 1e-12;
const db pi = acos(-1);
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const int mod = 1000 * 1000 * 1000 + 7;

int T;
int n, m;
int a[25005][27];
int b[25005][27];

pll dp[25005][27][3];

pll solve(int i, int j, int d){
    if(i == n) return {0, 0};
    pll &ret = dp[i][j][d];
    if(~ret.F) return ret;
    ret = solve(i + 1, j, 0);
    ret.F += a[i][j];
    // 1 means -> ans 2 means <-
    if(d != 1){ // going left
        if(j - 1 >= 0){
            pll tmp = solve(i, j - 1, 2);
            tmp.S += b[i][j - 1];
            if(tmp.F < ret.F) ret = tmp;
            else if(tmp.F == ret.F && tmp.S < ret.S) ret = tmp;
        }
    }
    if(d != 2){ // going right
        if(j + 1 < m){
            pll tmp = solve(i, j + 1, 1);
            tmp.S += b[i][j];
            if(tmp.F < ret.F) ret = tmp;
            else if(tmp.F == ret.F && tmp.S < ret.S) ret = tmp;
        }
    }
    return ret;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    sf(T);
    while(T--){
        sf(n), sf(m);
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j)
                sf(a[i][j]);
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m - 1; ++j)
                sf(b[i][j]);
        memset(dp, -1, sizeof dp);
        pll mnCost = solve(0, 0, 0);
        printf("%lld %lld\n", mnCost.F, mnCost.S);
    }
    return 0;
}