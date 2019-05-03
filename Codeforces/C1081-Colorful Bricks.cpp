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
const int mod = 998244353;

int n, m, k;
int dp[2020][2020];

int solve(int i, int rem) {
	if (rem < 0) return 0;
	if (i == n - 1) return (rem == 0);
	int &ret = dp[i][rem];
	if (~ret) return ret;
	ret = solve(i + 1, rem);
	ret += (solve(i + 1, rem - 1) * 1LL * (m - 1)) % mod;
	if (ret >= mod) ret -= mod;
	return ret;
}

int main() {
    cin >> n >> m >> k;
    memset(dp, -1, sizeof dp);
    cout << (m * 1LL * solve(0, k)) % mod << endl;
    return 0;
}
