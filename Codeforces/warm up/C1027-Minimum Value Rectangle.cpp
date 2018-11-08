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

int t, n;
int a, cnt[10005];

double getRatio(int w, int l) {
    double r = (w+l)*2.0*(w+l);
    r /= (w*1.0*l);
    return r;
}

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        vector<int> me;
        memset(cnt, 0, sizeof cnt);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a);
            cnt[a]++;
            if (cnt[a] % 2 == 0)
                me.push_back(a);
        }
        sort(all(me));
        double R = getRatio(me[0], me[1]);
        for (int i = 1; i < sz(me); ++i)
            R = min(R, getRatio(me[i], me[i - 1]));
        for (int i = sz(me) - 1 ; i > 0; --i)
            if (getRatio(me[i], me[i - 1]) == R) {
                printf("%d %d %d %d\n", me[i], me[i], me[i - 1], me[i - 1]);
                break;
            }
    }
    return 0;
}