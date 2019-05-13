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

int t, n;
int nxt[500500];
int p[500500];
int me;

int dfs(int u) {
	if (u == n + 1) return me;
	if (p[u] != -1) return me;
	p[u] = dfs((nxt[u] == -1 ? n + 1 : nxt[u]));
	me = p[u] - 1;
	return me;
}

int tree[4 * 500500];

int build(int id = 1, int l = 0, int r = n + 1) {
	if (r - l == 1) {
		return tree[id] = p[l];
	}
	int mid = (l + r) / 2;
	return tree[id] = max(build(id * 2, l, mid), build(id * 2 + 1, mid, r));
}

int query(int x, int y, int id = 1, int l = 0, int r = n + 1) {
	if (x >= r || l >= y) return 0;
	if (x <= l && r <= y) return tree[id];
	int mid = (l + r) / 2;
	return max(query(x, y, id * 2, l, mid), query(x, y, id * 2 + 1, mid, r));
}

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i)
			scanf("%d", &nxt[i]), nxt[i + 1] = 0, p[i] = -1;
		p[n + 1] = -1;
		me = n;
		for (int i = 1; i <= n; ++i)
			dfs(i);
		build();
		bool can = 1;
		for (int i = 1; i <= n; ++i) {
			if (nxt[i] == -1) continue;
			if (nxt[i] == i + 1) continue;
			int mx = query(i + 1, (nxt[i] == -1 ? n + 1 : nxt[i]));
			if (mx > p[i]) can = 0;
		}
		if (can == 0) {
			printf("-1\n");
			continue;
		}
		for (int i = 1; i <= n; ++i)
			printf("%d%c", p[i], " \n"[i==n]);
	}
    return 0;
}