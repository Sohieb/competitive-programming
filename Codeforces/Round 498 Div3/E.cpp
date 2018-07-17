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

int n, q;
vector<int> adj[200005];
int siz[200005];
vector<int> dfsOrder;
int idxOf[200005];

int dfs(int u){
    dfsOrder.push_back(u);
    siz[u] = 1;
    for(int i = 0; i < sz(adj[u]); ++i)
        siz[u] += dfs(adj[u][i]);
    return siz[u];
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    scanf("%d%d", &n, &q);
    for(int i = 2; i <= n; ++i){
        int p;
        scanf("%d", &p);
        adj[p].push_back(i);
    }
    dfs(1);
    for(int i = 0; i < sz(dfsOrder); ++i)
        idxOf[dfsOrder[i]] = i;
    int u, k;
    while(q--){
        scanf("%d%d", &u, &k);
        if(siz[u] < k){
            printf("%d\n", -1);
            continue;
        }
        printf("%d\n", dfsOrder[idxOf[u] + k - 1]);
    }
    return 0;
}
