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
char a[101][101];
int b[101][101];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            scanf(" %c", &a[i][j]);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            bool bad = 0;
            for (int k = 0; k < n; ++k)
                if (i != k && a[k][j] == a[i][j])
                    bad = 1;
            for (int k = 0; k < m; ++k)
                if (j != k && a[i][k] == a[i][j])
                    bad = 1;
            b[i][j] = bad;
        }
    string ans ="";
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (!b[i][j])
                ans += a[i][j];
    cout << ans << endl;
    return 0;
}
