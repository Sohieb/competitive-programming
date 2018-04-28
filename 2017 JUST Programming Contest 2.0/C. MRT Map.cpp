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
string sta[10005];
char name[22];
vector<pii> adj[10005];
int dist[10005];

int getCost(int u, int v){
    int cnt1[26], cnt2[26];
    memset(cnt1, 0, sizeof cnt1);
    memset(cnt2, 0, sizeof cnt2);
    for(int i = 0; i < sz(sta[u]); ++i)
        cnt1[sta[u][i] - 'a'] = 1;
    for(int i = 0; i < sz(sta[v]); ++i)
        cnt2[sta[v][i] - 'a'] = 1;
    int common = 0;
    for(int i = 0; i < 26; ++i)
        common += cnt1[i] * cnt2[i];
    return common;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; ++i){
        scanf("%s", name);
        sta[i] = string(name);
        for(int j = 0; j < sz(sta[i]); ++j)
            sta[i][j] = tolower(sta[i][j]);
    }
    for(int i = 0; i < m; ++i){
        int u, v;
        cin >> u >> v;
        int c = getCost(u, v);
        adj[u].push_back({c, v});
        adj[v].push_back({c, u});
        //cout << c << endl;
    }
    int src, des;
    cin >> src >> des;
    memset(dist, 0x3f, sizeof dist);
    priority_queue<pii> pq;
    dist[src] = 0;
    pq.push({0, src});
    while(!pq.empty()){
        pii me = pq.top();
        pq.pop();
        me.F *= -1;
        if(dist[me.S] < me.F)
            continue;
        for(int i = 0; i < sz(adj[me.S]); ++i){
            int v = adj[me.S][i].S;
            int w = adj[me.S][i].F;
            if(dist[v] <= dist[me.S] + w)
                continue;
            dist[v] = dist[me.S] + w;
            pq.push({-1 * dist[v], v});
        }
    }
    printf("%d\n", dist[des]);
    return 0;
}