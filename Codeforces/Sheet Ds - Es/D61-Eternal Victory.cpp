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
vector<pii> adj[100005];
ll mxPath;

void dfs(int u = 1, int p = -1, ll val = 0) {
	if (sz(adj[u]) == 1 && u != 1) {
		mxPath = max(mxPath, val);
		return;
	}
	for (auto v : adj[u]) 
		if (v.F != p) dfs(v.F, u, val + v.S);
}

int main() {
    scanf("%d", &n);
    if (n == 1)
    	return !printf("0\n");
    ll ans = 0;
    for (int i = 1; i < n; ++i) {
    	int u, v, w;
    	scanf("%d%d%d", &u, &v, &w);
    	adj[u].push_back({v, w});
    	adj[v].push_back({u, w});
    	ans += w + w;
    }
    dfs();
    ans -= mxPath;
    cout << ans << endl;
    return 0;
}
