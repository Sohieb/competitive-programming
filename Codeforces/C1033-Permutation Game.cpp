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
int c[100005];

int solve(int i) {
	if (c[i] != -1) return c[i];
	c[i] = 0;
	for (int d = 1; ; ++d) {
		int j = d * a[i];
		if (i + j > n && i - j < 1) break;
		if (i + j <= n && a[j + i] > a[i])
			c[i] |= (!solve(j + i));
		if (i - j >= 1 && a[i - j] > a[i])
			c[i] |= (!solve(i - j));
	}
	return c[i];
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
    	scanf("%d", &a[i]);
    }
    memset(c, -1, sizeof c);
    for (int i = 1; i <= n; ++i) {
    	if (c[i] ==-1) solve(i);
    	printf("%c", (c[i] ? 'A' : 'B'));
    }
    cout << endl;
    return 0;
}
