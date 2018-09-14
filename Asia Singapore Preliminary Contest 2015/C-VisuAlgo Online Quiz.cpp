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
int S, T;
vector<pair<int,int> > adj[10005];
int dist[10005];
int ways[10005];
int vis[10005];

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        adj[u].push_back({v, w});
    }
    scanf("%d%d", &S, &T);
    memset(dist, 0x3f, sizeof dist);
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    dist[S] = 0;
    pq.push({dist[S], S});
    while (!pq.empty()) {
        pii cur = pq.top();
        int u = cur.S;
        pq.pop();
        if (cur.F > dist[u])
            continue;
        for (auto xx : adj[u]) {
            int v = xx.F, w = xx.S;
            if (dist[v] <= dist[u] + w)
                continue;
            dist[v] = dist[u] + w;
            pq.push({dist[v], v});
        }
    }
    ways[S] = 1;
    vis[S] = 1;
    pq.push({dist[S], S});
    while (!pq.empty()) {
        pii cur = pq.top();
        int u = cur.S;
        pq.pop();
        for (auto xx : adj[u]) {
            int v = xx.F, w = xx.S;
            if (dist[v] == dist[u] + w) {
                ways[v] += ways[u];
                if (vis[v] == 0) {
                    pq.push({dist[v], v});
                    vis[v] = 1;
                }
            }
        }
    }
    printf("%d\n", ways[T]);
    return 0;
}
