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

int n, m;
pair<ll, ll> a[200200];
vector<pair<ll, pii> > edges;
int par[200200];

void init() {
    sort(all(edges));
    for (int i = 0; i <= n; ++i)
        par[i] = i;
}

int findSet(int u) {
    return (par[u] == u ? u : par[u] = findSet(par[u]));
}

bool isSameSet(int u, int v) {
    return (findSet(u) == findSet(v));
}

void unionSet(int u, int v) {
    if (isSameSet(u, v)) return;
    par[findSet(u)] = par[findSet(v)];
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%lld", &a[i].F);
        a[i].S = i + 1;
    }
    for (int i = 0; i < m; ++i) {
        ll u, v, w;
        scanf("%lld%lld%lld", &u, &v, &w);
        edges.push_back({w, {u ,v}});
    }
    sort(a, a + n);
    for (int i = 0; i < 5; ++i)
        for (int j = i + 1; j < n; ++j) 
            edges.push_back({a[i].F + a[j].F, {a[i].S, a[j].S}});
    init();
    ll MST = 0;
    for (int i = 0; i < sz(edges); ++i) {
        int u = edges[i].S.F;
        int v = edges[i].S.S;
        ll w = edges[i].F;
        //cout << u << " " << v << " " << w << endl;
        if (isSameSet(u, v)) continue;
        MST += w;
        unionSet(u, v);
    }
    cout << MST << endl;
    return 0;
}
