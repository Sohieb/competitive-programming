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
const int mod = 998244353;

int n;
int arr[200005];
int mx[200005];
int nxt[200005];
map<int, int> lst;

int dp[200005][3];

int solve(int i, int prev) {
    if (i == n - 1) return 1;
    int &ret = dp[i][prev];
    if (~ret) return ret;
    if (nxt[i] == i) {
        ret = solve(i + 1, prev) + solve(i + 1, prev ^ 1);
    } else {
        ret = solve(nxt[i], prev);
    }
    if (ret >= mod) ret -= mod;
    return ret;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &arr[i]), lst[arr[i]] = i;
    mx[0] = lst[arr[0]];
    for (int i = 1; i < n; ++i)
        mx[i] = max(mx[i - 1], lst[arr[i]]);
    for (int i = 0; i < n; ++i)
        nxt[i] = mx[lst[arr[i]]];
    memset(dp, -1, sizeof dp);
    printf("%d\n", solve(nxt[0], 0));
    return 0;
}
