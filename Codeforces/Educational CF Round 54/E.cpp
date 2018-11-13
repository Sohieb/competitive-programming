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

int n, q;
vector<int> adj[300005];
long long vForh[3000050];
vector<pair<int, int> > node[300005];
ll ans[300005];

void dfs(int u, int h, long long cur, int p = -1) {
    for (int i = 0; i < sz(node[u]); ++i) {
        vForh[h] += node[u][i].S;
        if (node[u][i].F < 300001)
            vForh[h + node[u][i].F + 1] -= node[u][i].S;
    }
    ans[u] = cur + vForh[h];
    for (int i = 0; i < sz(adj[u]); ++i) {
        if (adj[u][i] != p)
            dfs(adj[u][i], h + 1, cur + vForh[h], u);
    }
    for (int i = 0; i < sz(node[u]); ++i) {
        vForh[h] -= node[u][i].S;
        if (node[u][i].F < 300001)
            vForh[h + node[u][i].F + 1] += node[u][i].S;
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i < n; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    scanf("%d", &q);
    int u, d, x;
    while (q--) {
        scanf("%d%d%d", &u, &d, &x);
        node[u].push_back({d, x});
    }
    dfs(1, 1, 0);
    for (int i = 1; i <= n; ++i)
        printf("%lld%c", ans[i], " \n"[i==n]);
    return 0;
}