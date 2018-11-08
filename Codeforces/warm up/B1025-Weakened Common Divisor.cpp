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
pair<int, int> a[150005];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d%d", &a[i].F, &a[i].S);
    vector<int> divs;
    for (int i = 1; i <= 100000; ++i) {
        if (a[0].F % i == 0) {
            divs.push_back(i);
            divs.push_back(a[0].F/i);
        }
    }
    for (int i = 1; i <= 100000; ++i) {
        if (a[0].S % i == 0) {
            divs.push_back(i);
            divs.push_back(a[0].S/i);
        }
    }
    sort(all(divs));
    divs.resize(unique(all(divs)) - divs.begin());
    for (auto d : divs) {
        bool can = 1;
        for (int i = 0; i < n; ++i)
            if (a[i].F % d != 0 && a[i].S % d != 0)
                can = 0;
        if (can && d > 1) return !printf("%d\n", d);
    }
    printf("-1\n");
    return 0;
}