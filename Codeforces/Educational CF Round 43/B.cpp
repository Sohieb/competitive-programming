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

ll n, m, k;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    cin >> n >> m >> k;
    if(k < n)
        return !printf("%lld %d\n", k + 1, 1);
    k -= n - 1;
    int raw = (k + m - 2) / (m - 1);
    printf("%lld ", n - raw + 1);
    if(raw % 2 == 1)
        printf("%lld\n", 1 + k - (raw - 1) * (m - 1));
    else
        printf("%lld\n", m - k + (raw - 1) * (m - 1) + 1);
    return 0;
}
