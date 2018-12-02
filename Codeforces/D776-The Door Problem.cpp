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
int arr[100005];
vector<int> sw[100005];
vector<pii> adj[100005];
int col[100005];

bool dfs(int u, int p = 0, int wight = 0) {
    //cout << u << " " << p << " " << wight << endl;
    if (col[u] != -1) {
        if (wight == 0) {
            if (col[u] == col[p]) return 0;
            return 1;
        } else {
            if (col[u] == col[p]) return 1;
            return 0;
        }
    } else {
        if (wight == 0) {
            col[u] = !col[p];
        } else {
            col[u] = col[p];
        }
        bool can = 1;
        for (int i = 0; i < sz(adj[u]); ++i) {
            int v = adj[u][i].F;
            int w = adj[u][i].S;
            if (v == p) continue;
            can &= dfs(v, u, w);
        }
        return can;
    }
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &arr[i]);
    for (int i = 1; i <= m; ++i) {
        int x;
        scanf("%d", &x);
        for (int j = 0; j < x; ++j) {
            int room;
            scanf("%d", &room);
            sw[room].push_back(i);
        }
    }
    for (int i = 1; i <= n; ++i) {
        int v = sw[i][0];
        int u = sw[i][1];
        int w = arr[i];
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    memset(col, -1, sizeof col);
    bool ok = 1;
    for (int i = 1; i <= m; ++i)
        if (col[i] == -1) ok &= dfs(i);
    if (ok) cout << "YES\n";
    else cout << "NO\n";
    // for (int i = 1; i <= m; ++i)
    //     cout << i << " " << col[i] << endl;
    return 0;
}
