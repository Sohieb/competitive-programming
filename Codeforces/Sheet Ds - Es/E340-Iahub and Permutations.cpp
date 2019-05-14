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
int a[2020];
int b[2020];
int fac[2020];
int pas[2020][2020];

int get(int N, int R) {
	if (N == R) return 1;
	if (R == 0) return 1;
	if (R == 1) return N;
	int &ret = pas[N][R];
	if (~ret) return ret;
	ret = get(N - 1, R) + get(N - 1, R - 1);
	if (ret >= mod) ret -= mod;
	return ret;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    	scanf("%d", &a[i]), b[a[i]] = i;
    int mis = 0, can = 0;
    for (int i = 1; i <= n; ++i) {
    	mis += (a[i] == -1);
    	if (b[i] == 0 && a[i] == -1) ++can;
    }
    fac[0] = 1;
    for (int i = 1; i < 2020; ++i)
    	fac[i] = (fac[i - 1] * 1LL * i) % mod;
    memset(pas, -1, sizeof pas);
    int ans = 0;
    for (int i = 0; i <= can; ++i) {
    	ans += (i % 2 == 1 ? -1 : 1) * (get(can, i) * 1LL * fac[mis - i]) % mod;
    	if (ans < 0) ans += mod;
    	if (ans >= mod) ans -= mod;
    }
    cout << ans << endl;
    return 0;
}
