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

int T;
int n, x, y;
pii a[505];


int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d%d", &n, &x, &y);
        int j = -1;
        for (int i = 0; i < n; ++i) {
            scanf("%d%d", &a[i].F, &a[i].S);
            if (a[i].F <= x && a[i].S >= y) {
                if (j == -1) j = i;
                if (a[i].F < a[j].F) j = i;
                if (a[i].F == a[j].F && a[i].S > a[j].S) j = i;
            }
        }
        printf("%d\n", (j == -1) ? -1 : ++j);
    }
    return 0;
}