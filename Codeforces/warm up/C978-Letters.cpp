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
ll a[200005], b[200005];

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%lld", &a[i]);
        b[i] = a[i] + b[i - 1];
    }
    ll x;
    for (int i = 0; i < m; ++i) {
        scanf("%lld", &x);
        int l = 1, r = n, mid;
        while (l < r) {
            mid = l + (r - l) / 2;
            if (b[mid] - x >= 0)
                r = mid;
            else
                l = mid + 1;
        }
        printf("%d %lld\n", l, x - b[l - 1]);
    }
    return 0;
}
