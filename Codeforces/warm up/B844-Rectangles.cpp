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
int a[55][55];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            scanf("%d", &a[i][j]);
        }
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        int zero = 0, one = 0;
        for (int j = 0; j < m; ++j)
            if (a[i][j] == 0) ++zero;
            else ++one;
        ans += (1LL << one) - 1 + (1LL << zero) - 1;
    }
    for (int j = 0; j < m; ++j) {
        int zero = 0, one = 0;
        for (int i = 0; i < n; ++i)
            if (a[i][j] == 0) ++ zero;
            else ++one;
        ans += (1LL << one) - 1 + (1LL << zero) - 1;
    }
    ans -= n * m;
    cout << ans << endl;
    return 0;
}
