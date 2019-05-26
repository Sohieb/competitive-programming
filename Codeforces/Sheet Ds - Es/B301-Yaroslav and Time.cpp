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

int n, d;
pair<pii, int> arr[101];
int dist[101];

int dijkstra() {
    memset(dist, 0x3f, sizeof dist);
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    dist[1] = 0;
    pq.push({dist[1], 1});
    while (!pq.empty()) {
        pii me = pq.top();
        pq.pop();
        if (dist[me.S] < me.F) continue;
        int u = me.S;
        for (int i = 1; i <= n; ++i) {
            if (i == u) continue;
            int dif = abs(arr[i].F.F - arr[u].F.F)
                        + abs(arr[i].F.S - arr[u].F.S);
            dif *= d;
            dif -= arr[i].S;
            if (dist[i] <= dist[u] + dif)
                continue;
            dist[i] = dist[u] + dif;
            pq.push({dist[i], i});
        }
    }
    return dist[n];
}

int main() {
    scanf("%d%d", &n, &d);
    for (int i = 2; i < n; ++i)
        scanf("%d", &arr[i].S);
    for (int i = 1; i <= n; ++i)
        scanf("%d%d", &arr[i].F.F, &arr[i].F.S);
    int mn = dijkstra();
    cout << mn << endl;
    return 0;
}
