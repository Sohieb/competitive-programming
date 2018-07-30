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

const int MAXN = 40005;
const int MAXLG = 17;
const int SQRT = 444;
int n, q;
int arr[MAXN];
vector<int> comm;
vector<int> adj[MAXN];
vector<pair<pii, pii> > qu;
int ans[100005];
vector<int> tim;
int in[MAXN], out[MAXN];
int h[MAXN], par[MAXN][MAXLG];

void dfs(int v, int p=-1) {
    tim.push_back(v);
    in[v] = sz(tim) - 1;
    par[v][0] = p;
    if(~p) h[v] = h[p] + 1;
    for(int i = 1; i < MAXLG; ++i)
        if(~par[v][i - 1])
            par[v][i] = par[par[v][i - 1]][i - 1];
    for(auto u : adj[v])
        if(u - p) dfs(u, v);
    tim.push_back(v);
    out[v] = sz(tim) - 1;
}

int LCA(int v, int u) {
    if(h[v] < h[u]) swap(v, u);
    for(int i = MAXLG - 1; i >= 0; --i)
        if(~par[v][i] && h[par[v][i]] >= h[u])
            v = par[v][i];
    if(v == u) return v;
    for(int i = MAXLG - 1; i >= 0; --i)
        if(par[v][i] != par[u][i])
            v = par[v][i], u = par[u][i];
    return par[v][0];
}

bool cmp(pair<pii, pii> &a, pair<pii, pii> &b) {
    if(a.F.F / SQRT != b.F.F / SQRT)
        return a.F.F / SQRT < b.F.F / SQRT;
    return a.F.S < b.F.S;
}

int frqNode[MAXN];
int frqVal[100005];
int cnt;

void add(int idx) {
    int v = tim[idx];
    frqNode[v]++;
    if(frqNode[v] == 2) {
        --frqVal[arr[v]];
        if(frqVal[arr[v]] == 0)
            --cnt;
    }
    else {
        ++frqVal[arr[v]];
        if(frqVal[arr[v]] == 1)
            ++cnt;
    }
}

void remove(int idx) {
    int v = tim[idx];
    frqNode[v]--;
    if(frqNode[v] == 1) {
        ++frqVal[arr[v]];
        if(frqVal[arr[v]] == 1)
            ++cnt;
    } else {
        --frqVal[arr[v]];
        if(frqVal[arr[v]] == 0)
            --cnt;
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    scanf("%d%d", &n, &q);
    for(int i = 1; i <= n; ++i)
        scanf("%d", arr + i), comm.push_back(arr[i]);
    sort(all(comm));
    comm.resize(unique(all(comm)) - comm.begin());
    for(int i = 1; i <= n; ++i)
        arr[i] = lower_bound(all(comm), arr[i]) - comm.begin();
    for(int i = 1; i < n; ++i) {
        int v, u;
        scanf("%d%d", &v, &u);
        adj[v].push_back(u);
        adj[u].push_back(v);
    }
    memset(par, -1, sizeof par);
    dfs(1);
    for(int i = 0; i < q; ++i) {
        int v, u;
        scanf("%d%d", &v, &u);
        if(in[v] > in[u]) swap(v, u);
        int p = LCA(v, u);
        if(v == p) {
            qu.push_back({{in[v], in[u]}, {-1, i}});
        } else {
            qu.push_back({{out[v], in[u]}, {p, i}});
        }
    }
    sort(all(qu), cmp);
    int curL = qu[0].F.F, curR = qu[0].F.S;
    for(int i = curL; i <= curR; ++i)
        add(i);
    for(int i  =0; i < q; ++i){
        int L = qu[i].F.F, R = qu[i].F.S;
        while(curL > L) add(--curL);
        while(curR < R) add(++curR);
        while(curL < L) remove(curL++);
        while(curR > R) remove(curR--);
        ans[qu[i].S.S] = cnt;
        if(~qu[i].S.F && frqVal[arr[qu[i].S.F]] == 0)
            ++ans[qu[i].S.S];
    }
    for(int i = 0; i < q; ++i)
        printf("%d\n", ans[i]);
    return 0;
}
