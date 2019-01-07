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

int n;
vector<int> adj[100100];
ll s[100100];
ll a[100100];
int par[100100];

int main() {
    scanf("%d", &n);
    for (int i = 2; i <= n; ++i) {
        scanf("%d", &par[i]);
        adj[par[i]].push_back(i);
    }
    for (int i = 1; i <= n; ++i)
        scanf("%lld", &s[i]);
    ll ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (s[i] == -1) {
            ll mn = INF;
            for (auto v : adj[i])
                mn = min(mn, s[v]);
            s[i] = mn;
            if (sz(adj[i]) == 0) s[i] = s[par[i]];
        }
        if (s[i] < s[par[i]]) 
            return !printf("-1\n");
        a[i] = s[i] - s[par[i]];
        ans += a[i];
    }
    cout << ans << endl;
    return 0;
}