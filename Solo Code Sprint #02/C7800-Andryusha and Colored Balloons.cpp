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
vector<int> adj[200200];
int col[200200];
int vis[200200];
int par[200200];

int main() {
    scanf("%d", &n);
    for (int i = 1; i < n; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int C = 0, U = 1;
    for (int i = 1; i <= n; ++i) {
        if (1 + sz(adj[i]) > C)
            C = 1 + sz(adj[i]), U = i;
    }
    memset(col, -1, sizeof col);
    int cur = 0;
    queue<int> q;
    q.push(U);
    vis[U] = 1;
    while (!q.empty()) {
        if (cur == C) cur -= C;
        int me = q.front();
        q.pop();
        if (me == U || par[me] == U) {
            col[me] = cur++;
        } else {
            while (cur == col[par[me]] ||
             cur == col[par[par[me]]]) cur = (cur + 1) % C;
            col[me] = cur++;
        }
        for (auto v : adj[me]) {
            if (vis[v]) continue;
            par[v] = me;
            vis[v] = 1;
            q.push(v);
        } 
    }
    printf("%d\n", C);
    for (int i = 1; i <= n; ++i)
        printf("%d%c", 1 + col[i], " \n"[i==n]);
    return 0;
}