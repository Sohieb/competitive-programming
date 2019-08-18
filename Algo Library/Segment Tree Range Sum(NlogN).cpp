// This solution is for SPOJ - HORRIBLE - Horrible Queries
// https://www.spoj.com/problems/HORRIBLE/
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

const int N = 100005;
int T, n, q;
ll seg[4*N], lazy[4*N];

void upd(int id, int l, int r, ll x){
    lazy[id] += x;
    seg[id] += (r - l) * x;
}

void shift(int id, int l, int r){
    int mid = (l + r) / 2;
    upd(id * 2, l, mid, lazy[id]);
    upd(id * 2 + 1, mid, r, lazy[id]);
    lazy[id] = 0;
}

void update(int x, int y, int v, int id = 1, int l = 0, int r = n){
    if(x >= r || l >= y) return;
    if(x <= l && r <= y){
        upd(id, l, r, v);
        return;
    }
    shift(id, l, r);
    int mid = (l + r) / 2;
    update(x, y, v, id * 2, l, mid);
    update(x, y, v, id * 2 + 1, mid, r);
    seg[id] = seg[id * 2] + seg[id * 2 + 1];
}

ll query(int x, int y, int id = 1, int l = 0, int r = n){
    if(x >= r || l >= y) return 0;
    if(x <= l && r <= y) return seg[id];
    shift(id, l, r);
    int mid = (l + r) / 2;
    return query(x, y, id * 2, l, mid) + query(x, y, id * 2 + 1, mid, r);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    scanf("%d", &T);
    while(T--){
        scanf("%d%d", &n, &q);
        memset(seg, 0, sizeof seg);
        memset(lazy, 0, sizeof lazy);
        while(q--){
            int op, l, r, v;
            scanf("%d%d%d", &op, &l, &r);
            if(op == 0){
                scanf("%d", &v);
                update(l - 1, r, v);
            } else {
                printf("%lld\n", query(l - 1, r));
            }
        }
    }
    return 0;
}
