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
int a[100005];
int b[100005];
ll ans[100005];
vector<pll> hull; // (m, b)

long double getX(pll l1, pll l2) {
	if (l1.F == l2.F) return LL_INF;
	return ((l1.S - l2.S) * 1.0 / (l2.F - l1.F));
}

void add(ll m, ll b) {
	pll nwLine = {m, b};
	while (sz(hull) > 1 && getX(hull[sz(hull) - 2], nwLine) <= getX(hull[sz(hull) - 2], hull.back())) 
		hull.pop_back();
	hull.push_back(nwLine);
}

int ptr;
ll get(ll x) {
	ptr = min(ptr, sz(hull) - 1);
	while (ptr + 1 < sz(hull) && hull[ptr + 1].F * x + hull[ptr + 1].S <= hull[ptr].F * x + hull[ptr].S)
		++ptr;
	ll y = hull[ptr].F * x + hull[ptr].S;
	return y;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    	scanf("%d", &a[i]);
    for (int i = 0; i < n; ++i)
    	scanf("%d", &b[i]);
    if (n < 3) {
    	cout << (n == 1 ? 0 : a[n - 1] * 1LL * b[0]) << endl;
    	return 0;
    }
    ans[1] = a[1] * 1LL *  b[0];
    add(b[0], ans[0]);
    add(b[1], ans[1]);
    for (int i = 2; i < n; ++i) {
    	ans[i] = get(a[i]);
    	add(b[i], ans[i]);
    }
    cout << ans[n - 1] << endl;
    return 0;
}