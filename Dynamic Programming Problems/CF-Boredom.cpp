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

const db eps = 1e-12;
const db pi = acos(-1);
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const int mod = 1000 * 1000 * 1000 + 7;

int n;
int a[100005];
int f[100005];

ll dp[100005][2];

ll solve(int i, int j){
	if(i == 0)return 0;
	ll &ret = dp[i][j];
	if(~ret) return ret;
	ret = solve(i - 1, 0);
	if(j == 0)
		ret = max(ret, solve(i - 1, 1) + i * 1LL * f[i]);
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    cin >> n;
    for(int i = 0; i < n; ++i)
    	cin >> a[i], f[a[i]]++;
    memset(dp, -1, sizeof dp);
    printf("%lld\n", solve(100000, 0));
    return 0;
}
