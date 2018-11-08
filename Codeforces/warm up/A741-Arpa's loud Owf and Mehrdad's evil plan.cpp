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

int n, a[105], b[105], vis[105];
set<int> s;

ll gcd(ll a, ll b) {
    return (b==0?a:gcd(b, a % b));
}

ll lcm(ll a, ll b) {
    return (a / gcd(a, b) * b);
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]), s.insert(a[i]);
    if (sz(s) < n)
        return !printf("-1\n");
    for (int i = 1; i <= n; ++i) {
        memset(vis, 0, sizeof vis);
        int cnt = 0, cur = i;
        while (vis[cur] == 0) {
            ++cnt;
            vis[cur] = 1;
            cur = a[cur];
        }
        if (cnt % 2) b[i] = cnt;
        else b[i] = cnt / 2;
    }
    ll ans = 1;
    for (int i = 1; i <= n; ++i)
        ans = lcm(ans, b[i]);
    printf("%lld\n", ans);
    return 0;
}