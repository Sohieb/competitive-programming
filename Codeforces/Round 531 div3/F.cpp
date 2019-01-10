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
int arr[17][10005];
bool can[17][17];
bool endd[17][17];

bool init(int K) {
    memset(can, 0, sizeof can);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            if (i == j) continue;
            bool tmp = 1;
            for (int k = 0; k < m; ++k)
                if (abs(arr[i][k] - arr[j][k]) < K) tmp = 0;
            can[i][j] = can[j][i] = tmp;
            tmp = 1;
            for (int k = 1; k < m; ++k)
                if (abs(arr[i][k] - arr[j][k - 1]) < K) tmp = 0;
            endd[i][j] = tmp;
        }
}

int dp[(1<<16) + 5][17][17];

int solve(int msk, int lst, int st) {
    if ((msk & ((1<<n) - 1)) == ((1<<n) - 1)) {
        return endd[st][lst];
    }
    int &ret = dp[msk][lst][st];
    if (~ret) return ret;
    ret = 0;
    for (int i = 0; i < n; ++i) {
        if (msk & (1<<i)) continue;
        if (can[i][lst] == 0) continue;
        ret |= solve(msk | (1 << i), i, st);
    }
    return ret;
}

bool ok(int K) {
    memset(dp, -1, sizeof dp);
    bool yess = 0;
    for (int i = 0; i < n && !yess; ++i)
        yess |= solve((1 << i), i, i);
    return yess;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            scanf("%d", &arr[i][j]);
    if (n == 1) {
        int ans = INF;
        for (int j = 1; j < m; ++j)
            ans = min(ans, abs(arr[0][j] - arr[0][j - 1]));
        return !printf("%d\n", ans);
    }
    int l = 0, r = 1000000000, mid;
    while (l < r) {
        mid = l + (r - l + 1) / 2;
        init(mid);
        if (ok(mid)) l = mid;
        else r = mid - 1;
    }
    cout << l << endl;
    return 0;
}
