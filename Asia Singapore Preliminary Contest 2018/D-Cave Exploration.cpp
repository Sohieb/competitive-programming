#include <bits/stdc++.h>

using namespace std;
using namespace __gnu_cxx;

typedef double db;
typedef long long ll;
typedef pair<db, db> pdd;
typedef pair<ll, ll> pll;
typedef pair<int, int> ii;
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

vector<int> dfs_low;
vector<int> dfs_num;
vector<int> dfs_parent;
vector<int> articulation_vertex;
int dfsNumberCounter;
int dfsRoot;
int rootChildren;
vector<ii> AdjList[N];

map<pair<int,int>, bool> isBridge;

void articulationPointAndBridge(int u) {
    dfs_low[u] = dfs_num[u] = dfsNumberCounter++;
    for (int j = 0; j < (int)AdjList[u].size(); j++) {
        ii v = AdjList[u][j];
        if (dfs_num[v.first] == 0) {
            dfs_parent[v.first] = u;
            if (u == dfsRoot) rootChildren++;
            articulationPointAndBridge(v.first);
            if (dfs_low[v.first] >= dfs_num[u])
                articulation_vertex[u] = true;
            if (dfs_low[v.first] > dfs_num[u]){
                //printf(" Edge (%d, %d) is a bridge\n", u, v.first);
                isBridge[{u, v.first}] = 1;
                isBridge[{v.first, u}] = 1;
            }
            dfs_low[u] = min(dfs_low[u], dfs_low[v.first]); 
        }
        else if (v.first != dfs_parent[u])
        dfs_low[u] = min(dfs_low[u], dfs_num[v.first]);
    } 
}

int n, m;
int vis[N];

int dfs(int u = 0) {
    vis[u] = 1;
    for (int i = 0; i < sz(AdjList[u]); ++i) {
        int v = AdjList[u][i].first;
        if (isBridge[{u, v}]) continue;
        if (vis[v]) continue;
        dfs(v);
    }
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        AdjList[u].push_back({v, 1});
        AdjList[v].push_back({u, 1});
    }

    dfsNumberCounter = 0;
    dfs_num.assign(N, 0);
    dfs_low.assign(N, 0);
    dfs_parent.assign(N, 0);
    articulation_vertex.assign(N, 0);
    for (int i = 0; i < N; i++)
        if (dfs_num[i] == 0) {
            dfsRoot = i;
            rootChildren = 0;
            articulationPointAndBridge(i);
            articulation_vertex[dfsRoot] = (rootChildren > 1);
        }
    dfs();
    int ans = 0;
    for (int i = 0; i < n; ++i)
        ans += vis[i]; 
    printf("%d\n", ans);
    return 0;
}