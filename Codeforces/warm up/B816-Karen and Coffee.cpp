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

int n, k, q;
int l, r;
int a[200005];

int main() {
    scanf("%d%d%d", &n, &k, &q);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &l, &r);
        a[l]++;
        a[r + 1]--;
    }
    for (int i = 1; i < 200005; ++i)
        a[i] += a[i - 1];
    for (int i = 0; i < 200005; ++i)
        a[i] = (a[i] >= k);
    for (int i = 1; i < 200005; ++i)
        a[i] += a[i - 1];
    while (q--) {
        scanf("%d%d", &l, &r);
        printf("%d\n", a[r] - a[l - 1]);
    }
    return 0;
}
