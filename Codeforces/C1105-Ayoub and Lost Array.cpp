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

int n, l, r;
int dp[200005][3];
int divs[3];

int solve(int i, int rem) {
	if (i == n) return (rem == 0);
	int &ret = dp[i][rem];
	if (~ret) return ret;
	ret = (solve(i + 1, rem) * 1LL * divs[0]) % mod;
	if (ret >= mod) ret -= mod;
	ret += (solve(i + 1, (rem + 1) % 3) * 1LL * divs[1]) % mod;
	if (ret >= mod) ret -= mod;
	ret += (solve(i + 1, (rem + 2) % 3) * 1LL * divs[2]) % mod;
	if (ret >= mod) ret -= mod;
	return ret;
}

int main() {
    cin >> n >> l >> r;
    if (r - l < 100) {
    	while (l <= r) {
    		divs[l % 3]++;
    		++l;
    	}
    } else {
    	while (l % 3 != 1) {
    		divs[l % 3]++;
    		++l;
    	}
    	while (r % 3 != 0) {
    		divs[r % 3]++;
    		--r;
    	}
    	divs[0] += (r / 3) - (l - 1) / 3;
    	divs[1] += (r / 3) - (l - 1) / 3;
    	divs[2] += (r / 3) - (l - 1) / 3;
    }
    memset(dp, -1, sizeof dp);
    cout << solve(0, 0) << endl;
    return 0;
}
