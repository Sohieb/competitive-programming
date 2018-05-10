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

const db eps = 1e-12;
const db pi = acos(-1);
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const int mod = 1000 * 1000 * 1000 + 7;

int n, m;
vector<int> adj[200005];
int vis[200005];
vector<int> curNodes;

void dfs(int u){
    vis[u] = 1;
    curNodes.push_back(u);
    for(auto v : adj[u])
        if(!vis[v])
            dfs(v);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    sf(n), sf(m);
    for(int i = 0; i < m; ++i){
        int u, v;
        sf(u), sf(v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int CC = 0;
    for(int i = 1; i <= n; ++i){
        if(vis[i]) continue;
        curNodes.clear();
        dfs(i);
        bool cyc = 1;
        if(sz(curNodes) < 3)
            cyc = 0;
        for(int i = 0; i < sz(curNodes); ++i)
            if(sz(adj[curNodes[i]]) != 2)
                cyc = 0;
        CC += cyc;
    }
    printf("%d\n", CC);
    return 0;
}