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

ll n, m;
char x[1000005], y[1000005];
int cnt[1000005][26];

ll gcd(ll a, ll b) {
	return (!b ? a : gcd(b, a % b));
}

ll lcm(ll a, ll b) {
	return a / gcd(a, b) * b;
}

int main() {
    scanf("%lld%lld%s%s", &n, &m, x, y);
    ll lenX = strlen(x);
    ll lenY = strlen(y);
    int g = gcd(lenX, lenY);
    for (int i = 0; y[i]; ++i)
    	cnt[i % g][y[i] - 'a']++;
    ll bad = 0;
    for (int i = 0; x[i]; ++i)
    	bad += cnt[i % g][x[i] - 'a'];
    ll total = n * lenX;
    ll no = total / lcm(lenX, lenY);
    total -= bad * no;
    cout << total << endl;
    return 0;
}
