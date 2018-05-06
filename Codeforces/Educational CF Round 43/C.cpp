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

int n;
pair<pii, int> a[300005];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    sf(n);
    for(int i = 0; i < n; ++i)
        sf(a[i].F.F), sf(a[i].F.S), a[i].S = i + 1;
    sort(a, a + n, [](pair<pii, int> x, pair<pii, int> y){
        return (x.F.F == y.F.F ? x.F.S > y.F.S : x.F.F < y.F.F);
    });
    for(int i = 1; i < n; ++i){
        if(a[i].F.S <= a[i - 1].F.S)
            return !printf("%d %d\n", a[i].S, a[i - 1].S);
    }
    printf("-1 -1\n");
    return 0;
}
