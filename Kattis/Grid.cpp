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
int arr[505][505];
int dx[] = {1, 0, 0, -1};
int dy[] = {0, -1, 1, 0};

int dijkstra() {
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    int dist[505 * 505];
    memset(dist, 0x3f, sizeof dist);
    dist[0] = 0;
    pq.push({dist[0], 0});
    while (!pq.empty()) {
        pii me = pq.top();
        pq.pop();
        int x = me.S / m;
        int y = me.S % m;
        for (int i = 0; i < 4; ++i) {
            int xx = x + arr[x][y] * dx[i];
            int yy = y + arr[x][y] * dy[i];
            if (xx < 0 || xx >= n || yy < 0 || yy >= m)
                continue;
            if (dist[xx * m + yy] <= me.F + 1)
                continue;
            dist[xx * m + yy] = me.F + 1;
            pq.push({dist[xx * m + yy], xx * m + yy});
        }
    }
    return dist[(n - 1) * m + m - 1];
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            char c;
            scanf(" %c", &c);
            arr[i][j] = c - '0';
        }
    int ans = dijkstra();
    if (ans > 500 * 500)
        cout << -1 << endl;
    else
        cout << ans << endl;
    return 0;
}
