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

int n, k;
ll tree[1000005];

ll get(int x) {
    ll sum = 0;
    while (x) {
        sum += tree[x];
        x -= (x & -x);
    }
    return sum;
}

 void upd(int x) {
    while (x < 1000005) {
        tree[x]++;
        x += (x & -x);
    }
 }

int main() {
    scanf("%d%d", &n, &k);
    k = min(k, n - k);
    ll cur = 1, ans = 1;
    for (int i = 1; i <= n; ++i) {
        int nxt = cur + k;
        ll intersect;
        if (nxt > n) nxt -= n;
        if (nxt > cur) {
            intersect = get(nxt - 1) - get(cur);
        } else {
            intersect = get(n) - get(cur) + get(nxt - 1);
        }
        //cout << endl << cur << " " << nxt << " " << intersect << endl;
        upd(cur);
        upd(nxt);
        cur = nxt;
        ans += intersect + 1;
        printf("%lld%c", ans, " \n"[i==n]);
    }
    return 0;
}
