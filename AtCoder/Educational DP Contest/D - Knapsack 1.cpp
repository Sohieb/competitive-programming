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

int n, w;
pair<int, int> arr[105];
ll dp[105][100005];

ll solve(int i, int cur) {
    if (cur > w) return -LL_INF;
    if (i == n) return 0;
    ll &ret = dp[i][cur];
    if (~ret) return ret;
    ret = max(solve(i + 1, cur), solve(i + 1, cur + arr[i].F) + arr[i].S);
    return ret;
}

int main() {
    scanf("%d%d", &n, &w);
    for (int i = 0; i < n; ++i)
        scanf("%d%d", &arr[i].F, &arr[i].S);
    memset(dp, -1, sizeof dp);
    cout << solve(0, 0) << endl;
    return 0;
}
