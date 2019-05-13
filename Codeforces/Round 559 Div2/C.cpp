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
int a[100100], b[100100];

int main() {
    scanf("%d%d", &n, &m);
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
    	scanf("%d", &a[i]);
    }
    for (int i = 0; i < m; ++i) {
    	scanf("%d", &b[i]);
    	ans += b[i];
    }
    sort(a, a + n, greater<int>());
    sort(b, b + m);
    if (b[0] < a[0])
    	return !printf("-1\n");
    if (a[0] == b[0]) {
    	for (int i = 1; i < n; ++i)
    		ans += m * 1LL * a[i];
    } else {
    	ans += a[0];
    	ans += (m - 1) * 1LL * a[1];
    	for (int i = 2; i < n; ++i)
    		ans += m * 1LL * a[i];
    }
    cout << ans << endl;
    return 0;
}