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

const int N = 100005;
int n, q;
double tree[N];

void update(int i, double v) {
    while (i <= n) {
        tree[i] += v;
        i += (i & -i);
    }
}

double get(int i) {
    double res = 0;
    while (i) {
        res += tree[i];
        i -= (i & -i);
    }
    return res;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        double a;
        scanf("%lf", &a);
        update(i, a);
    }
    scanf("%d", &q);
    int type, e, l, r;
    double v;
    while (q--) {
        scanf("%d", &type);
        if (type == 1) {
            scanf("%d%lf", &e, &v);
            double old = get(e) - get(e - 1);
            update(e, v - old);
        } else {
            scanf("%d%d", &l, &r);
            printf("%.6lf\n", (get(r) - get(l - 1)) / (r - l + 1));
        }
    }
    return 0;
}
