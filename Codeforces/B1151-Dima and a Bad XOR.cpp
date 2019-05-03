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

int n, m;
int arr[505][505];
int dp[505][2048];

int solve(int i, int v) {
	if (i == n) return v;
	int &ret = dp[i][v];
	if (~ret) return ret;
	for (int j = 0; j < m; ++j)
		ret = max(ret, solve(i + 1, v ^ arr[i][j]));
	return ret;
}

void trace(int i, int v) {
	if (i == n) return;
	int &ret = dp[i][v];
	for (int j = 0; j < m; ++j) {
		if (solve(i + 1, v ^ arr[i][j]) == ret) {
			printf("%d%c", j + 1, " \n"[i==n-1]);
			trace(i + 1, v ^ arr[i][j]);
			return;
		}
	}
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j)
			scanf("%d", &arr[i][j]);
	}
	memset(dp, -1, sizeof dp);
	if (solve(0, 0) == 0)
		return printf("NIE\n"), 0;
	printf("TAK\n");
	trace(0, 0);
    return 0;
}
