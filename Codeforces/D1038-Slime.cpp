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

const db eps = 1e-9;
const db pi = acos(-1);
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const int mod = 1000 * 1000 * 1000 + 7;

int n, a[500500];
ll dp[500500][2][2][2];

ll solve(int i, int j, int k, int w) {
    if (i == n) return (k&w?0:-LL_INF);
    ll &ret = dp[i][j][k][w];
    if (~ret) return ret;
    ret = max(solve(i + 1, 0, k | j, w | !j), solve(i + 1, 1, k | j, w | !j)) + a[i] * (j?-1:1);
    return ret;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    if (n == 1) return !printf("%d\n", a[0]);
    memset(dp, -1, sizeof dp);
    printf("%lld\n", max(solve(0, 0, 0, 1), solve(0, 1, 1, 0)));
    return 0;
}
