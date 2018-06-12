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
int a[1005], b[1005];
ll dp[1005][1005];

ll solve(int i, int j){
    if(i == n && j == m) return 0;
    ll &ret = dp[i][j];
    if(~ret) return ret;
    ret = LL_INF;
    if(i < n) ret = min(ret, solve(i + 1, j) + a[i] * j);
    if(j < m) ret = min(ret, solve(i, j + 1) + b[j] * i);
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
        for(int i = 1; i < n; ++i)
            sf(a[i]);
        for(int i = 1; i < m; ++i)
            sf(b[i]);
        sort(a + 1, a + n, greater<int>());
        sort(b + 1, b + m, greater<int>());
        memset(dp, -1, sizeof dp);
        printf("%lld\n", solve(1, 1));
    }
    return 0;
}
