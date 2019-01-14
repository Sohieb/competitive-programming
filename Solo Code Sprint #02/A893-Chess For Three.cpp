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

int n, win;

int main() {
    int p1 = 1, p2 = 2, p3 = 3;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        // cout << p1 << " " << p2 << endl;
        cin >> win;
        if (win != p1 && win != p2)
            return !printf("NO\n");
        if (win == p1) swap(p2, p3);
        else swap(p1, p3);
    }
    cout << "YES\n";
    return 0;
}
