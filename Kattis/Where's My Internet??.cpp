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
vector<int> adj[200005];
int vis[200005];

void dfs(int u) {
	vis[u] = 1;
	for (auto v : adj[u])
		if (!vis[v]) dfs(v);
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) {
    	int u, v;
    	scanf("%d%d", &u, &v);
    	adj[u].push_back(v);
    	adj[v].push_back(u);
    }
    dfs(1);
    vector<int> bad;
    for (int i = 1; i <= n; ++i)
    	if (vis[i] == 0)
    		bad.push_back(i);
    if (sz(bad) == 0)
    	return !printf("Connected\n");
    for (int i = 0; i < sz(bad); ++i)
    	printf("%d\n", bad[i]);
    return 0;
}
