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
double p[3030];
double dp[3030][3030];

double solve(int i, int cnt) {
    if (i == n) return (cnt > n / 2 ? 1 : 0);
    double &ret = dp[i][cnt];
    if (ret == ret) return ret;
    ret = solve(i + 1, cnt + 1) * p[i] + solve(i + 1, cnt) * (1 - p[i]);
    return ret;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%lf", &p[i]);
    memset(dp, -1, sizeof dp);
    printf("%.9lf\n", solve(0, 0));
    return 0;
}
