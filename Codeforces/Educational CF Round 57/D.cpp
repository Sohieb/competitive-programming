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
char str[100100];
int a[100100];
ll dp[100100][6];
string tmp = "hard";

ll solve(int i, int j) {
    if (j == 4) return LL_INF;
    if (i == n) return 0;
    ll &ret = dp[i][j];
    if (~ret) return ret;
    ret = solve(i + 1, j + (tmp[j] == str[i]));
    ret = min(ret, solve(i + 1, j) + a[i]);
    return ret;
}

int main() {
    scanf("%d%s", &n, str);
    for (int i = 0; i < n; ++i)
        scanf("%d", &a[i]);
    memset(dp, -1, sizeof dp);
    printf("%lld\n", solve(0, 0));
    return 0;
}
