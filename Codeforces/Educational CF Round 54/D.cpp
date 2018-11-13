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

int n, m, k;
vector<pair<int, pair<int, int> > > adj[300005];
long long dis[300005];
vector<int> ans;

void dijkstra() {
    memset(dis, 0x3f, sizeof dis);
    dis[1] = 0;
    priority_queue<pair<ll, pii>, vector<pair<ll, pii> >, greater<pair<ll, pii> > > pq;
    pq.push({dis[1], {1, -1}});
    while (!pq.empty()) {
        pair<ll, pii> me = pq.top();
        pq.pop();
        if (me.F > dis[me.S.F])
            continue;
        ans.push_back(me.S.S + 1);
        int u = me.S.F;
        for (int i = 0; i < sz(adj[u]); ++i) {
            int v = adj[u][i].F;
            int w = adj[u][i].S.F;
            int idx = adj[u][i].S.S;
            if (dis[v] <= dis[u] + w)
                continue;
            dis[v] = dis[u] + w;
            pq.push({dis[v], {v, idx}});
        }
    }
}

int main() {
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        adj[u].push_back({v, {w, i}});
        adj[v].push_back({u, {w, i}});
    }
    dijkstra();
    ans.resize(min(k + 1, sz(ans)));
    printf("%d\n", sz(ans) - 1);
    for (int i = 1; i < sz(ans); ++i)
        printf("%d%c", ans[i], " \n"[i==sz(ans)-1]);
    return 0;
}   