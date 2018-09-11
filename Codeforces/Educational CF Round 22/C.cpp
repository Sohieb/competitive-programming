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

const int N = 200005;
int n, x;
vector<int> adj[N];
int par[N];
int hi[N];
int far[N];

int dfs(int v, int p = -1) {
    par[v] = p;
    if (~p) hi[v] = hi[p] + 1;
    far[v] = hi[v];
    for (auto u : adj[v]) 
        if (u - p) far[v] = max(far[v], dfs(u, v));
    return far[v];
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    scanf("%d%d", &n, &x);
    for (int i = 1; i < n; ++i) {
        int v, u;
        scanf("%d%d", &v, &u);
        adj[v].push_back(u);
        adj[u].push_back(v);
    }
    dfs(1);
    int ans = 0;
    int me = x;
    while (me - 1) {
        if (hi[x] - hi[me] < hi[me]) 
            ans = max(ans, 2 * far[me]);
        me = par[me];
    }
    cout << ans << endl;
    return 0;
}
