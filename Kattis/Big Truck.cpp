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
int a[105];
vector<pii> adj[105];

bool cmp(pair<int, pii> a, pair<int, pii> b) {
    if (a.S.F != b.S.F)
        return a.S.F > b.S.F;
    return a.S.S < b.S.S;
}

pii dijkstra() {
    priority_queue<pair<int, pii>, vector<pair<int, pii>>, decltype(&cmp)> pq(&cmp);
    pii dist[105];
    for (int i = 0; i <= n; ++i)
        dist[i] = {0x3f3f3f3f, a[i]};
    dist[1] = {0, a[1]};
    pq.push({1, dist[1]});
    while (!pq.empty()) {
        pair<int, pii> curNode = pq.top();
        pq.pop();
        if (curNode.S.F > dist[curNode.F].F)
            continue;
        for (auto node : adj[curNode.F]) {
            int v = node.F, d = node.S;
            if (dist[v].F > curNode.S.F + d) {
                dist[v] = {curNode.S.F + d, curNode.S.S + a[v]};
                pq.push({v, dist[v]});
            } else if (dist[v].F == curNode.S.F + d && dist[v].S < curNode.S.S + a[v]) {
                dist[v] = {curNode.S.F + d, curNode.S.S + a[v]};
                pq.push({v, dist[v]});
            }
        }
    }
    return dist[n];
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    scanf("%d", &m);
    for (int i = 0; i < m; ++i) {
        int a, b, d;
        scanf("%d%d%d", &a, &b, &d);
        adj[a].push_back({b, d});
        adj[b].push_back({a, d});
    }
    pii ans = dijkstra();
    if (ans.F > 100000)
        cout << "impossible\n";
    else
        cout << ans.F << " " << ans.S << endl;
    return 0;
}
