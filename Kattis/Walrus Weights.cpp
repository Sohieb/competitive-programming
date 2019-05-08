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
int a[1010];
int dp[1010][2020];

int solve(int i, int has) {
	if (has < 0) return 0;
	if (i == n) return (has == 0);
	int &ret = dp[i][has];
	if (~ret) return ret;
	ret = solve(i + 1, has);
	ret |= solve(i + 1, has - a[i]);
	return ret;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    	scanf("%d", &a[i]);
    memset(dp, -1, sizeof dp);
    int ans = 0;
    for (int i = 1; i < 2020; ++i) {
    	if (solve(0, i) == 0)
    		continue;
    	if (abs(1000 - i) <= abs(1000 - ans))
    		ans = i;
    }
    cout << ans << endl;
    return 0;
}
