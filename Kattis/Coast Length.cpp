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
int arr[1010][1010];
int vis[1010][1010];

void dfs(int x, int y) {
	if (x == 0 || x > n || y == 0 || y > m) return;
	if (vis[x][y]) return;
	if (arr[x][y] == 1) return;
	vis[x][y] = 1;
	dfs(x + 1, y);
	dfs(x - 1, y);
	dfs(x, y + 1);
	dfs(x, y - 1);
}

int main() {
    scanf("%d%d", &n, &m);
    char tmp;
    vector<pii> init;
    for (int i = 1; i <= n; ++i)
    	for (int j = 1; j <= m; ++j) {
    		scanf(" %c", &tmp);
    		arr[i][j] = tmp == '1';
    		if (arr[i][j] == 0 && (i == 1 || j == 1 || i == n || j == m))
    			init.push_back({i, j});
    	}
    for (int i = 0; i < sz(init); ++i) 
    	if (!vis[init[i].F][init[i].S])
    		dfs(init[i].F, init[i].S);
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
    	for (int j = 1; j <= m; ++j) {
    		if (arr[i][j] == 0) continue;
    		if (arr[i + 1][j] == 0) ++ans;
    		if (arr[i - 1][j] == 0) ++ans;
    		if (arr[i][j + 1] == 0) ++ans;
    		if (arr[i][j - 1] == 0) ++ans;
    		vis[i][j] = -1;
    	}
    }
    for (int i = 1; i <= n; ++i) {
    	for (int j = 1; j <= m; ++j) {
    		if (vis[i][j]) continue;
    		if (vis[i + 1][j] == -1) --ans;
    		if (vis[i - 1][j] == -1) --ans;
    		if (vis[i][j + 1] == -1) --ans;
    		if (vis[i][j - 1] == -1) --ans;
    	}
    }
    cout << ans << endl;
    return 0;
}
