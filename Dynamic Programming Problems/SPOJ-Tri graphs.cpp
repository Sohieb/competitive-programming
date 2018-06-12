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

int n;
int arr[100005][5];
ll dp[100005][5];

ll solve(int i, int j){
    if(i == n){
        if(j == 2) return arr[i][2];
        if(j == 1) return arr[i][1] + arr[i][2];
        return LL_INF;
    }
    ll &ret = dp[i][j];
    if(~ret) return ret;
    ret = solve(i + 1, j) + arr[i][j];
    if(j - 1 > 0)
        ret = min(ret, solve(i + 1, j - 1) + arr[i][j]);
    if(j + 1 < 4)
        ret = min(ret, solve(i + 1, j + 1) + arr[i][j]),
        ret = min(ret, solve(i, j + 1) + arr[i][j]);
    return ret;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    for(int C = 1; ; ++C){
        sf(n);
        if(n == 0)
            break;
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j < 4; ++j)
                sf(arr[i][j]);
        memset(dp, -1, sizeof dp);
        printf("%d. %lld\n", C, solve(1, 2));
    }
    return 0;
}
