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

const db eps = 1e-12;
const db pi = acos(-1);
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const int mod = 1000 * 1000 * 1000 + 7;

int n, m, s;
int vis1[5050];
int vis2[5050];
int bad[5050];
vector<int> adj[5050];

void dfs1(int u){
    vis1[u] = 1;
    for(auto v : adj[u])
        if(!vis1[v]) dfs1(v);
}

int dfs2(int u){
    vis1[u] = 1;
    vis2[u] = 1;
    int b = bad[u];
    for(int i = 0; i < sz(adj[u]); ++i)
        if(vis2[adj[u][i]] == 0)
            b += dfs2(adj[u][i]);
    bad[u] = 0;
    return b;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    cin >> n >> m >> s;
    for(int i = 0; i < m; ++i){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    dfs1(s);
    int ans = 0;
    for(int i = 1; i <= n; ++i){
        if(vis1[i]) continue;
        adj[s].push_back(i);
        memset(vis2, 0, sizeof vis2);
        ans += 1 - dfs2(i);
        bad[i] = 1;
        adj[s].pop_back();
    }
    printf("%d\n", ans);
    return 0;
}
