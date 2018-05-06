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

int n, m, cL, cE, v;
int q;
int a[100005];
int b[100005];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    cin >> n >> m >> cL >> cE >> v;
    for(int i = 0; i < cL; ++i)
        sf(a[i]);
    for(int i = 0; i < cE; ++i)
        sf(b[i]);
    sf(q);
    while(q--){
        int x, y, xx, yy;
        scanf("%d%d%d%d", &x, &y, &xx, &yy);
        int res = n + m + n + m;
        if(x == xx)
            res = abs(y - yy);
        // using only salalem
        if(cL > 0){
            int j = lower_bound(a, a + cL, y) - a;
            if(j == cL) --j;
            res = min(res, abs(x - xx) + abs(y - a[j]) + abs(yy - a[j]));
            if(j != 0)
                res = min(res, abs(x - xx) + abs(y - a[j - 1]) + abs(yy - a[j - 1]));
        }
        // using only elevator
        if(cE > 0){
            int difX = abs(x - xx);
            int stp = (difX + v - 1) / v;
            int j = lower_bound(b, b + cE, y) - b;
            if(j == cE) --j;
            res = min(res, stp + abs(y - b[j]) + abs(yy - b[j]));
            if(j != 0)
                res = min(res, stp + abs(y - b[j - 1]) + abs(yy - b[j - 1]));
        }
        printf("%d\n", res);
    }
    return 0;
}