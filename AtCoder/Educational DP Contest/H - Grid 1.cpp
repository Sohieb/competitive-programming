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

int n, m;
char arr[1010][1010];
int dp[1010][1010];

int solve(int i, int j) {
    if (i == n || j == m) return 0;
    if (arr[i][j] == '#') return 0;
    if (i == n - 1 && j == m - 1) return 1;
    int &ret = dp[i][j];
    if (~ret) return ret;
    ret = solve(i + 1, j) + solve(i, j + 1);
    if (ret >= mod) ret -= mod;
    return ret;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            scanf(" %c", &arr[i][j]);
    memset(dp, -1, sizeof dp);
    printf("%d\n", solve(0, 0));
    return 0;
}
