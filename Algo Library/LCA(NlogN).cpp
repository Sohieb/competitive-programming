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

const int MAXN = 100005, MAXLG = 20;
int par[MAXN][MAXLG]; // initially all -1
int h[MAXN];
vector<int> adj[MAXN];

//Build
void dfs(int v, int p = -1) {
    par[v][0] = p;
    if (p != -1) h[v] = h[p] + 1;
    for (int i = 1; i < MAXLG; ++i)
        if (par[v][i - 1] != -1)
            par[v][i] = par[par[v][i - 1]][i - 1];
    for (auto u : adj[v])
        if (u != p) dfs(u, v);
}

int LCA(int v, int u) {
    if (h[v] < h[u])
        swap(v, u);
    for (int i = MAXLG - 1; i >= 0; --i)
        if (par[v][i] != -1 && h[par[v][i]] >= h[u])
            v = par[v][i];
    // now h[v] = h[u]
    if (v == u) return v;
    for (int i = MAXLG - 1; i >= 0; --i)
        if (par[v][i] != par[u][i])
            v = par[v][i], u = par[u][i];
    return par[v][0];
}

int main() {
    
    return 0;
}
