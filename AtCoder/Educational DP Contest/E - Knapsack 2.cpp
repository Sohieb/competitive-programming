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

int n, w, V;
pair<int, int> arr[105];
ll dp[105][100005];

ll solve(int i, int has) {
    if (i == n) return (has >= V ? 0 : LL_INF);
    ll &ret = dp[i][has];
    if (~ret) return ret;
    ret = min(solve(i + 1, has), solve(i + 1, has + arr[i].S) + arr[i].F);
    return ret;
}

int main() {
    scanf("%d%d", &n, &w);
    for (int i = 0; i < n; ++i)
        scanf("%d%d", &arr[i].F, &arr[i].S);
    int l = 1, r = 100000, mid;
    while (l < r) {
        mid = l + (r - l + 1) / 2;
        memset(dp, -1, sizeof dp);
        V = mid;
        if (solve(0, 0) <= w) l = mid;
        else r = mid - 1;
    }
    cout << l << endl;
    return 0;
}
