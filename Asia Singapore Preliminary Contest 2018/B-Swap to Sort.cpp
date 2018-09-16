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
int a[1000006];
int par[1000006];

int findSet(int u) {
    return (u == par[u] ? u : par[u] = findSet(par[u]));
}

bool isSameSet(int u, int v) {
    return findSet(u) == findSet(v);
}

void unionSet(int u, int v) {
    if (isSameSet(u, v)) return;
    par[findSet(u)] = par[findSet(v)];
}


int main() {
    cin >> n >> k;
    for (int i = 0; i < 1000005; ++i)
        par[i] = i;
    for (int i = 1; i <= n; ++i)
        a[i] = n - i + 1;
    for (int i = 0; i < k; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        unionSet(u, v);
    }
    bool can = 1;
    for (int i = 1; i <= n; ++i) {
        //cout << i << " " << a[i] << " => " << findSet(i) << " " << findSet(a[i]) << endl;
        if (isSameSet(i, a[i]) == 0)
            can = 0;
    }
    printf(can ? "YES\n" : "NO\n");
    return 0;
}
