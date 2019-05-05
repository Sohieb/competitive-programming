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
int a[55][55];
int b[55][55];
int c[55][55];

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i)
    	for (int j = 0; j < m; ++j)
    		scanf("%d", &a[i][j]);
    for (int i = 0; i < n; ++i)
    	for (int j = 0; j < m; ++j)
    		scanf("%d", &b[i][j]);
    for (int i = 0; i < n; ++i)
    	for (int j = 0; j < m; ++j) {
    		if (a[i][j] > b[i][j]) swap(a[i][j], b[i][j]);
    		if (a[i][j] <= a[i - 1][j] || a[i][j] <= a[i][j - 1])
    			return !printf("Impossible\n");
    		if (b[i][j] <= b[i - 1][j] || b[i][j] <= b[i][j - 1])
    			return !printf("Impossible\n");
    	}
    printf("Possible\n");
    return 0;
}