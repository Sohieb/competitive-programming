// !FromHere
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

int n, q;
int arr[100005];
struct node {
	int lft, rght, ans; // [left, right, answer]
	int frqLft, frqRght, frqAns;
	node(){}
	node(int _x, int _y, int _z, int _fx, int _fy, int _fz) {
		lft = _x, rght = _y, ans = _z, frqLft = _fx, frqRght = _fy, frqAns = _fz;
	}
}tree[400005];

node merge(node &a, node &b) {
	node nw;
	nw.lft = a.lft, nw.frqLft = a.frqLft;
	if (a.lft == b.lft) nw.frqLft += b.frqLft;
	nw.rght = b.rght, nw.frqRght = b.frqRght;
	if (a.rght == b.rght) nw.frqRght += a.frqRght;

	if (a.frqAns >= b.frqAns) nw.ans = a.ans, nw.frqAns = a.frqAns;
	else nw.ans = b.ans, nw.frqAns = b.frqAns;

	if (a.rght == b.lft && a.frqRght + b.frqLft > nw.frqAns)
		nw.ans = a.rght, nw.frqAns = a.frqRght + b.frqLft;
	return nw;
}

void build(int id = 1, int l = 0, int r = n) {
	if (r - l < 2) {
		tree[id] = node(arr[l], arr[l], arr[l], 1, 1, 1);
		return;
	}
	int mid = (l + r) / 2;
	build(id * 2, l, mid);
	build(id * 2 + 1, mid, r);
	tree[id] = merge(tree[id * 2], tree[id * 2 + 1]);
}

node query(int x, int y, int id = 1, int l = 0, int r = n) {
	if (x >= r || l >= y) return node(0, 0, 0, 0, 0,0);
	if (x <= l && r <= y) return tree[id];
	int mid = (l + r) / 2;
	node left = query(x, y, id * 2, l, mid);
	node right = query(x, y, id * 2 + 1, mid, r);
	return merge(left, right);
}

int main() {	
    while (scanf("%d%d", &n, &q), n != 0) {
    	for (int i = 0; i < n; ++i)
    		scanf("%d", &arr[i]);
	    build();
	    while (q--) {
	    	int l, r;
	    	scanf("%d%d", &l, &r);
	    	printf("%d\n", query(l - 1, r).frqAns);
	    }
    }
    return 0;
}
