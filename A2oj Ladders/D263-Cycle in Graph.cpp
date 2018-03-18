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

int n, m, k;
vector<int> adj[100005];
int col[100005];
int pos[100005];
vector<int> cur;

void dfs(int u, int p){
    cur.push_back(u);
    pos[u] = sz(cur) - 1;
    col[u] = -1;
    for(auto v : adj[u]){
        if(col[v] == 1 || v == p)
            continue;
        if(col[v] == -1 && sz(cur) - pos[v] > k){
            printf("%d\n", sz(cur) - pos[v]);
            for(int i = pos[v]; i < sz(cur); ++i)
                printf("%d%c", cur[i], " \n"[i == sz(cur) - 1]);
            exit(0);
        }
        if(col[v] == 0)
            dfs(v, p);
    }
    col[u] = 1;
    cur.pop_back();
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#endif
	cin >> n >> m >> k;
    for(int i = 0; i < m; ++i){
        int a, b;
        sf(a), sf(b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    memset(pos, -1, sizeof pos);
    dfs(1, 0);
    return 0;
}