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

int n, a[300300];

bool ok(int k) {
	for (int i = 0; i < n; ++i) {
		int mn = min(a[i], a[0]);
		if (k * 1LL * (abs(i - 0)) > mn) return 0;
		mn = min(a[i], a[n - 1]);
		if (k * 1LL * (abs(n - 1 - i)) > mn) return 0;
	}
	return 1;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    	scanf("%d", &a[i]);
    int l = 0, r = 1000000000, mid;
    while (l < r) {
    	mid = l + (r - l + 1) / 2;
    	if (ok(mid)) l = mid;
    	else r = mid - 1;
    }
    cout << l << endl;
    return 0;
}