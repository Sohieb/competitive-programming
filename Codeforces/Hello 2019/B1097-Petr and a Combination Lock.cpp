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
int a[16];

bool solve(int i, int cur) {
    if (cur >= 360) cur %= 360;
    if (cur < 0) cur += 360;
    if (i == n) return (cur == 0);
    return (solve(i + 1, cur + a[i]) || solve(i + 1, cur - a[i]));
}

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    if (solve(0, 0))
        cout << "YES\n";
    else
        cout << "NO\n";
    return 0;
}
