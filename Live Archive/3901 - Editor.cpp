#include <bits/stdc++.h>
 
using namespace std;
 
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
 
int T, n;
char str[5005];

int pwr[2][5005];
int base[2];
int MOD[2];

void init() {
	base[0] = 133, base[1] = 151;
	MOD[0] = 1000000009, MOD[1] = 1000003111;
	pwr[0][0] = pwr[1][0] = 1;
	for (int i = 1; i < 5005; ++i)
		pwr[0][i] = pwr[0][i - 1] * 133LL % MOD[0],
		pwr[1][i] = pwr[1][i - 1] * 151LL % MOD[1];
}

set<pii> st;

bool can(int len) {
	if (len == 0) return 1;
	if (len == n) return 0;
	st.clear();
	pii me;
	for (int i = 0; i < len; ++i)
		me.F = (me.F * 1LL * base[0] + str[i]) % MOD[0],
		me.S = (me.S * 1LL * base[1] + str[i]) % MOD[1];
	st.insert(me);
	for (int i = len; i < n; ++i) {
		me.F -= str[i - len] * 1LL * pwr[0][len - 1] % MOD[0];
		if (me.F < 0) me.F += MOD[0];
		me.S -= str[i - len] * 1LL * pwr[1][len - 1] % MOD[1];
		if (me.S < 0) me.S += MOD[1];
		me.F = (me.F * 1LL * base[0] + str[i]) % MOD[0];
		me.S = (me.S * 1LL * base[1] + str[i]) % MOD[1];
		if (st.find(me) != st.end()) return 1;
		st.insert(me);
	}
	return 0;
}

int main() {
	init();
	scanf("%d", &T);
	while (T--) {
		scanf("%s", str);
		n = strlen(str);
		int l = 0, r = n, mid;
		while (l < r) {
			mid = l + (r - l + 1) / 2;
			if (can(mid)) l = mid;
			else r = mid - 1;
		}
		printf("%d\n", l);
	}
	return 0;
}
