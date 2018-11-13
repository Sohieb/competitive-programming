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

const db eps = 1e-12;
const db pi = acos(-1);
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const int mod = 1000 * 1000 * 1000 + 7;

int t, n;

int main() {
    cin >> t;
    while (t--) {
        scanf("%d", &n);
        if (n == 0) {
            printf("Y 0.0 0.0\n");
            continue;
        }
        if (n < 4) {
            printf("N\n");
            continue;
        }
        if (n == 4) {
            printf("Y 2.0 2.0\n");
            continue;
        }
        double l = n - 2, r = n - 1;
        while (r - l > eps) {
            double mid = l + (r - l) / 2.0;
            if (mid * (n - mid) > n) l = mid;
            else r = mid;
        }
        printf("Y %.9f %.9f\n", l, n - l);
    }
    return 0;
}