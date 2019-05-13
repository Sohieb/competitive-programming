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
vector<int> adj[100005];
int rnk[100005];
bool done[100005];

void solve(int st, int pr, char c) {
	queue<pair<int, pii> > q;
	q.push({st, {pr, 0}});
	int far1, far2;
	while (!q.empty()) {
		pair<int, pii> me = q.front();
		q.pop();
		for (auto v : adj[me.F]) {
			if (done[v]) continue;
			if (v == pr) continue;
			if (v == me.S.F) continue;
			q.push({v, {me.F, me.S.S + 1}});
		}
		far1 = me.F;
	}
	q.push({far1, {pr, 0}});
	int d;
	while (!q.empty()) {
		pair<int, pii> me = q.front();
		q.pop();
		for (auto v : adj[me.F]) {
			if (done[v]) continue;
			if (v == pr) continue;
			if (v == me.S.F) continue;
			q.push({v, {me.F, me.S.S + 1}});
		}
		far2 = me.F;
		d = me.S.S;
	}
	int cent;
	q.push({far2, {pr, 0}});
	while (!q.empty()) {
		pair<int, pii> me = q.front();
		if (me.S.S == d / 2) cent = me.F;
		q.pop();
		for (auto v : adj[me.F]) {
			if (done[v]) continue;
			if (v == pr) continue;
			if (v == me.S.F) continue;
			q.push({v, {me.F, me.S.S + 1}});
		}
		far2 = me.F;
	}
	rnk[cent] = c;
	done[cent] = 1;
	for (auto v : adj[cent])
		if (v != pr && !done[v])
			solve(v, cent, c + 1);
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i < n; ++i) {
    	int u, v;
    	scanf("%d%d", &u, &v);
    	adj[u].push_back(v);
    	adj[v].push_back(u);
    }
    solve(1, -1, 'A');
    for (int i = 1; i <= n; ++i) {
    	if (rnk[i] > 'Z')
    		return !printf("Impossible!\n");
    }
    for (int i = 1; i <= n; ++i)
    	printf("%c%c", char(rnk[i]), " \n"[i==n]);
    return 0;
}
