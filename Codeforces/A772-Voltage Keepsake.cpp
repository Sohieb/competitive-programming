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

int n, p;
pii arr[100005];

bool can(double tim) {
    double need = 0;
    for (int i = 0; i < n; ++i) {
        double me = arr[i].F * tim;
        me = max(0.0, me - arr[i].S);
        need += me;
    }
    return (need <= tim * p);
}

int main() {
    scanf("%d%d", &n, &p);
    for (int i = 0; i < n; ++i) 
        scanf("%d%d", &arr[i].F, &arr[i].S);
    double l = 0, r = 10000000000000, mid;
    int safe = 600;
    while (r - l > eps && safe--) {
        mid = l + (r - l + eps) / 2.0;
        if (can(mid)) l = mid;
        else r = mid - eps;
    }
    if (l >= 999999999999) l = -1;
    printf("%.9f\n", l);
    return 0;
}
