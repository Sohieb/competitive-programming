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

int n, m, a[1005], b[1005];
char s[501];
string str;
map<string, int> id;
int cnt[2005], curId;

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%s", s);
        str = s;
        id[str] = ++curId;
        cnt[curId]++;
        a[i] = curId;
    }
    for (int i = 0; i < m; ++i) {
        scanf("%s", s);
        str = s;
        if (id.count(str) == 0)
            id[str] = ++curId;
        cnt[id[str]]++;
        b[i] = id[str];
    }
    int a1 = 0, a2 = 0, b1 = 0, b2 = 0;
    for (int i = 0; i < n; ++i)
        (cnt[a[i]] == 1 ? ++a1 : ++a2);
    for (int i = 0; i < m; ++i)
        (cnt[b[i]] == 1 ? ++b1 : ++b2);
    int hasA = (a2 + 1) / 2 + a1;
    int hasB = b2 / 2 + b1;
    printf(hasA > hasB ? "YES\n" : "NO\n");
    return 0;
}
