/*
Author: Sohieb Mohamed (aka.Sohieb)

Idea: 
    -   A greedy problem, You need to observe that taking some vertex
        will always be better than leaveing it and taking all the smaller ones.

    -   We can try to think of which nodes we need to pick instead of which ones
        we need to remove.

    -   First take the node number N, then iterate over the remaining one in decreaseing order.
        maintain a tree that contains the current picked nodes.
        try to add the next one to it, iff the distance from it to any picked node is less then
        the remaining available number of nodes to be picked.

    -   we can achive this using LCA, by rooting the tree from node number N.        
*/

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

int n, k;
vector<int> adj[1000005];
int vis[1000005];
int h[1000005];
const int MAXLG = 22;
int par[1000005][MAXLG];

void dfs(int v, int p = -1){
    par[v][0] = p;
    if(~p) h[v] = h[p] + 1;
    for(int i = 1; i < MAXLG; ++i)
        if(~par[v][i - 1])
            par[v][i] = par[par[v][i - 1]][i - 1];
    for(auto u : adj[v])
        if(u - p) dfs(u, v);
}

int getVisPar(int v){
    for(int i = MAXLG - 1; i >= 0; --i)
        if(~par[v][i] && vis[par[v][i]] == 0)
            v = par[v][i];
    return par[v][0];
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    cin >> n >> k;
    for(int i = 1; i < n; ++i){
        int u, v;
        scanf("%d%d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    memset(par, -1, sizeof par);
    dfs(n);
    vis[n] = 1;
    int rem = n - k - 1;
    for(int i = n - 1; i > 0 && rem; --i){
        if(vis[i]) continue;
        int u = getVisPar(i);
        if(h[i] - h[u] > rem)
            continue;
        u = i;
        while(vis[u] == 0){
            --rem;
            vis[u] = 1;
            u = par[u][0];
        }
    }
    for(int i = 1; i <= n; ++i)
        if(vis[i] == 0)
            printf("%d ", i);
    return 0;
}
