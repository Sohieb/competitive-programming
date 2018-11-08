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

int n;
char a[1000005], b[1000005];

int main() {
    scanf("%d%s%s", &n, a, b);
    int out = 0;
    for (int i = 0; i < n - 1; ++i) {
        if (a[i] != a[i + 1] && b[i] != b[i + 1] && a[i] != b[i]) {
            swap(a[i], a[i + 1]);
            ++out;
        }
    }
    for (int i = 0; a[i]; ++i)
        out += (a[i] != b[i]);
    printf("%d\n", out);
    return 0;
}