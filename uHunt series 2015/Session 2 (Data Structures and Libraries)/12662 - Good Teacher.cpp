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

int n, q, x;
string names[105];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        cin >> names[i];
    scanf("%d", &q);
    while (q--) {
        scanf("%d", &x);
        if (names[x] != "?") {
            printf("%s\n", names[x].c_str());
            continue;
        }
        int l = x - 1, r = x + 1;
        while (l > 0 && names[l] == "?") --l;
        while (r <= n && names[r] == "?") ++r;
        if (l < 1) {
            for (int i = x; i < r; ++i)
                printf("left of ");
            printf("%s\n", names[r].c_str());
        } else if (r > n) {
            for (int i = l; i < x; ++i)
                printf("right of ");
            printf("%s\n", names[l].c_str());
        } else {
            if (x - l < r - x) {
                for (int i = l; i < x; ++i)
                    printf("right of ");
                printf("%s\n", names[l].c_str());
            } else if (x - l > r - x) {
                for (int i = x; i < r; ++i)
                    printf("left of ");
                printf("%s\n", names[r].c_str());
            } else {
                printf("middle of %s and %s\n", names[l].c_str(), names[r].c_str());
            }
        }
    }
    return 0;
}
