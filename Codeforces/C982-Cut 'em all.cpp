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
vector<int> adj[100100];
int siz[100100];
int ans;

int dfs(int u, int p = -1) {
    siz[u] = 1;
    for (int i = 0; i < sz(adj[u]); ++i)
        if (adj[u][i] != p) siz[u] += dfs(adj[u][i], u);
    if (siz[u] % 2 == 0 && u != 1) ++ans;
    return siz[u];
}

int main() {
    cin >> n;
    if (n % 2 == 1) return !printf("-1\n");
    for (int i = 1; i < n; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);
    cout << ans << endl;
    return 0;
}