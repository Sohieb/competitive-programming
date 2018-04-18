#include <bits/stdc++.h>

using namespace std;
using namespace __gnu_cxx;

typedef double db;
typedef long long ll;
typedef pair<int,int> ii;

#define F        first
#define S        second
#define pnl      printf("\n")
#define sz(x)    (int)x.size()
#define sf(x)    scanf("%d",&x)
#define pf(x)    printf("%d\n",x)
#define all(x)   x.begin(),x.end()
#define rall(x)  x.rbegin(),x.rend()
#define FOR(a,b) for(int i = a; i < b; ++i)

const db eps = 1e-12;
const db pi = acos(-1);
const int inf = 0x3f3f3f3f;
const ll INF = inf * 2LL * inf;
const int mod = 1000 * 1000 * 1000 + 7;

int T;
int n, q;
ll seg[400010];
ll lazy[400010];

void upd(int id, int l, int r, ll v){
    lazy[id] += v;
    seg[id] += (r - l) * v;
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

ll getSum(int x, int y, int id = 1, int l = 0, int r = n){
    if(x >= r || l >= y) return 0;
    if(x <= l && r <= y) return seg[id];
    shift(id, l, r);
    int mid = (l + r) / 2;
    return getSum(x, y, id * 2, l, mid) + getSum(x, y, id * 2 + 1, mid , r);
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
            int type, l, r, v;
            scanf("%d%d%d", &type, &l, &r);
            if(type == 0){
                scanf("%d", &v);
                update(l - 1, r, v);
            } else {
                printf("%lld\n", getSum(l - 1, r));
            }
        }
    }	
    return 0;
}