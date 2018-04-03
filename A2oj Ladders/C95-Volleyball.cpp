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
int x, y;
vector<pair<int,int> > adj[1010];
vector<pair<int,int> > adj2[1010];
pair<int,int> taxi[1010];
ll dist[1010][1010];

void dijkstra(int src){
    dist[src][src] = 0;
    typedef pair<ll,int > node;
    priority_queue<node, vector<node>, greater<node> > pq;
    pq.push({dist[src][src], src});
    while(!pq.empty()){
        node me = pq.top();
        pq.pop();
        if(me.F > dist[src][me.S])
            continue;
        for(int i = 0; i < sz(adj[me.S]); ++i){
            int w = adj[me.S][i].F;
            int v = adj[me.S][i].S;
            if(dist[src][v] <= dist[src][me.S] + w)
                continue;
            dist[src][v] = dist[src][me.S] + w;
            pq.push({dist[src][v], v});
        }
    }
}

ll dijkstra(int x, int y){
    memset(dist, 0x3f, sizeof dist);
    dist[x][x] = 0;
    typedef pair<ll,int > node;
    priority_queue<node, vector<node>, greater<node> > pq;
    pq.push({dist[x][x], x});
    while(!pq.empty()){
        node me = pq.top();
        pq.pop();
        if(me.F > dist[x][me.S])
            continue;
        for(int i = 0; i < sz(adj2[me.S]); ++i){
            int w = adj2[me.S][i].F;
            int v = adj2[me.S][i].S;
            if(dist[x][v] <= dist[x][me.S] + w)
                continue;
            dist[x][v] = dist[x][me.S] + w;
            pq.push({dist[x][v], v});
        }
    }
    return dist[x][y];
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#endif
	scanf("%d%d%d%d", &n, &m, &x, &y);
    for(int i = 0; i < m; ++i){
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
    }
    for(int i = 1; i <= n; ++i)
        scanf("%d%d", &taxi[i].F, &taxi[i].S);
    memset(dist, 0x3f, sizeof dist);
    for(int i = 1; i <= n; ++i)
        dijkstra(i);
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j){
            if(i == j) continue;
            if(dist[i][j] <= taxi[i].F)
                adj2[i].push_back({taxi[i].S, j});
        }
    ll res = dijkstra(x, y);
    if(res < 10000000000000LL)
        cout << res << endl;
    else
        cout << -1 << endl;
    return 0;
}