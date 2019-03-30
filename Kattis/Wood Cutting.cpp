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
int n, w, a;
vector<int> v;

int main() {
    scanf("%d", &T);
    while (T--) {
        v.clear();
        scanf("%d", &n);
        double sum = 0, ans = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &w);
            int tmp = 0;
            for (int j = 0; j < w; ++j) {
                scanf("%d", &a);
                tmp += a;
            }
            v.push_back(tmp);
        }
        sort(all(v));
        for (int i = 0; i < sz(v); ++i)
            sum = sum + v[i], ans += sum;
        ans = ans / n;
        printf("%.9f\n", ans);
    }
    return 0;
}
