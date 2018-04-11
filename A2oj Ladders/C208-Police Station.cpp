#include <bits/stdc++.h>

using namespace std;
using namespace __gnu_cxx;

typedef double db;
typedef long long ll;
typedef pair<int,int> ii;

#define F        first
#define S        second
#define pnl      printf("\n")
#define sz(x)    (int)x.size()
#define sf(x)    scanf("%d",&x)
#define pf(x)    printf("%d\n",x)
#define all(x)   x.begin(),x.end()
#define rall(x)  x.rbegin(),x.rend()
#define FOR(a,b) for(int i = a; i < b; ++i)

const db eps = 1e-12;
const db pi = acos(-1);
const int inf = 0x3f3f3f3f;
const ll INF = inf * 2LL * inf;
const int mod = 1000 * 1000 * 1000 + 7;

int n, m;
int adj[105][105];
int mat[105][105];
ll to1N[2][105];
int vis[105];

void solve(int u, int flag){
    queue<int> q;
    q.push(u);
    to1N[flag][u] = 1;
    while(!q.empty()){
        int me = q.front();
        q.pop();
        if(vis[me])
            continue;
        vis[me] = 1;
        for(int i = 1; i <= n; ++i){
            if(adj[me][i] == 0)
                continue;
            if(vis[i]){
                if(mat[me][(flag==0?1:n)] - 1 == mat[i][(flag==0?1:n)])
                    to1N[flag][me] += to1N[flag][i];
            } else {
                q.push(i);
            }
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    scanf("%d%d", &n, &m);
    memset(mat, 0x3f, sizeof mat);
    for(int i = 0; i < m; ++i){
        int u, v;
        scanf("%d%d", &u, &v);
        mat[u][v] = mat[v][u] = 1;
        adj[u][v] = adj[v][u] = 1;
    }
    for(int i = 1; i <= n; ++i)
        mat[i][i] = 0;
    for(int k = 1; k <= n; ++k)
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= n; ++j)
                mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
    solve(1, 0);
    memset(vis, 0, sizeof vis);
    solve(n, 1);
    int edgOne = 0, edgN = 0;
    for(int i = 1; i <= n; ++i)
        if(adj[1][i] && mat[i][n] + 1 == mat[1][n])
            ++edgOne;
    for(int i = 1; i <= n;++i)
        if(adj[n][i] && mat[i][1] + 1 == mat[n][1])
            ++edgN;
    double res = 0;
    res = max(res, edgOne * 1.0 / to1N[0][n]);
    res = max(res, edgN * 1.0 / to1N[0][n]);
    for(int i = 2; i < n; ++i){
        if(mat[1][i] + mat[i][n] > mat[1][n])
            continue;
        double safe = 2 * to1N[0][i] * to1N[1][i];
        res = max(res, safe / to1N[0][n]);
    }
    printf("%.15f\n", res);
    return 0;
}