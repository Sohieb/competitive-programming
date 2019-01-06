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

int n, k, a[100100];
int dp[100100];

int solve(int i) {
    if (i == n) return 0;
    int &ret = dp[i];
    if (~ret) return ret;
    ret = INF;
    for (int j = 1; j <= k; ++j)
        if (i + j <= n)
            ret = min(ret, solve(i + j) + abs(a[i] - a[i + j]));
    return ret;
}

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    memset(dp, -1, sizeof dp);
    printf("%d\n", solve(1));
    return 0;
}
