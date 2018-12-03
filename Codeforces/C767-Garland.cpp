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
int root;
int par[1000005];
int arr[1000005];
int bad[1000005];
vector<int> adj[1000005];

int sub1 = -1, sub2 = -1;

int dfs(int u = root) {
    for (int i = 0; i < sz(adj[u]); ++i)
        arr[u] += dfs(adj[u][i]);
    return arr[u];
}

int dfs1(int u = root) {
    for (int i = 0; i < sz(adj[u]); ++i)
        bad[u] += dfs1(adj[u][i]);
    if (arr[u] == arr[root] / 3 && sub1 == -1 && u != root) sub1 = u, bad[u] = arr[u];
    return bad[u];
}

void dfs2(int u = root) {
    if (u == sub1) return;
    for (int i = 0; i < sz(adj[u]); ++i)
        dfs2(adj[u][i]);
    if (arr[u] - bad[u] == arr[root] / 3 && sub2 == -1 && u != root) sub2 = u;
    return;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d%d", &par[i], &arr[i]);
        adj[par[i]].push_back(i);
        if (par[i] == 0) root = i;
    }
    dfs();
    if (arr[root] % 3 != 0)
        return !printf("-1\n");
    dfs1();
    dfs2();
    if (sub1 == -1 || sub2 == -1)
        return !printf("-1\n");
    return !printf("%d %d\n", sub1, sub2);
    return 0;
}
