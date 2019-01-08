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

int n;
int a[100100][3];
int dp[100100][4];

int solve(int i, int lst) {
    if (i == n) return 0;
    int &ret = dp[i][lst];
    if (~ret) return ret;
    for (int j = 0; j < 3; ++j)
        if (j != lst) ret = max(ret, solve(i + 1, j) + a[i][j]);
    return ret;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < 3; ++j)
            scanf("%d", &a[i][j]);
    memset(dp, -1, sizeof dp);
    printf("%d\n", solve(0, 3));
    return 0;
}
