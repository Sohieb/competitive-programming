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

int n, m, d;
pii a[200005];
int ans[200005];

int main() {
    scanf("%d%d%d", &n, &m, &d);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i].F);
        a[i].S = i;
    }
    sort(a, a + n);
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    for (int i = 0; i < n; ++i) {
        if (!pq.empty() && a[i].F - pq.top().F > d) {
            pii me = pq.top();
            pq.pop();
            pq.push({a[i].F, me.S});
            ans[a[i].S] = me.S;
        } else {
            ans[a[i].S] = 1 + sz(pq);
            pq.push({a[i].F, ans[a[i].S]});
        }
    }
    printf("%d\n", sz(pq));
    for (int i = 0; i < n; ++i)
        printf("%d%c", ans[i], " \n"[i==n-1]);
    return 0;
}
