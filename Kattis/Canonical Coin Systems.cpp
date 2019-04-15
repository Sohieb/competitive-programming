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

int n, a[105], dp[3000005];
int greedy[2000005];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    memset(dp, 0x3f, sizeof dp);
    memset(greedy, 0x3f, sizeof greedy);
    dp[0] = 0;
    greedy[0] = 0;
    int k = 1;
    for (int i = 0; i < a[n] + a[n - 1]; ++i) {
    	for (int j = 1; j <= n; ++j) {
    		dp[i + a[j]] = min(dp[i + a[j]], dp[i] + 1);
    	}
    	if (i == 0) continue;
    	while (k < n && a[k + 1] <= i) ++k;
        greedy[i] = greedy[i - a[k]] + 1;
        // cout << i << " " << greedy[i] << " " << dp[i] << endl;
        if (greedy[i] != dp[i]) {
            return !printf("non-canonical\n");
        }
    }
    printf("canonical\n");
    return 0;
}