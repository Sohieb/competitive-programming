#include <bits/stdc++.h>

using namespace std;
using namespace __gnu_cxx;

typedef double db;
typedef long long ll;
typedef pair<int, int> ii;

#define F        first
#define S        second
#define pnl      printf("\n")
#define sz(x)    (int)x.size()
#define sf(x)    scanf("%d",&x)
#define pf(x)    printf("%d\n",x)
#define all(x)   x.begin(),x.end()
#define rall(x)  x.rbegin(),x.rend()
#define FOR(a,b) for(int i = a; i < b; ++i)

const db eps = 1e-12;
const db pi = acos(-1);
const int inf = 0x3f3f3f3f;
const ll INF = inf * 2LL * inf;
const int mod = 1000 * 1000 * 1000 + 7;

int n, m;
vector<int> adj[150005];
int vis[150005];

vector<int> com;
void dfs(int u) {
    vis[u] = 1;
    com.push_back(u);
    for (int i = 0; i < sz(adj[u]); ++i) {
        int v = adj[u][i];
        if (!vis[v])
            dfs(v);
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; ++i) {
        if (vis[i])
            continue;
        com.clear();
        dfs(i);
        for (int j = 0; j < sz(com); ++j)
            if (sz(adj[com[j]]) != sz(com) - 1)
                return 0 * printf("NO\n");
    }
    printf("YES\n");
    return 0;
}