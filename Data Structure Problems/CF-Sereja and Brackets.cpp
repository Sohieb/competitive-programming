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

char str[1000005];
int n, q;
pair<ii, int> seg[4000005];

pair<ii, int> merge(pair<ii, int> a, pair<ii, int> b){
    pair<ii, int> c;
    c.S = a.S + b.S;
    int more = min(a.F.F, b.F.S);
    c.S += more;
    c.F.F = b.F.F + a.F.F - more;
    c.F.S = a.F.S + b.F.S - more;
    return c;
}

void build(int id = 1, int l = 0, int r = n){
    if(r - l < 2){
        seg[id] = {{str[l] == '(', str[l] == ')'}, 0};
        return;
    }
    int mid = (l + r) / 2;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid, r);
    seg[id] = merge(seg[id*2], seg[id*2 + 1]);
}

pair<ii, int> query(int x, int y, int id = 1, int l = 0, int r = n){
    if(x >= r || l >= y) return {{0, 0}, 0};
    if(x <= l && r <= y) return seg[id];
    int mid = (l + r) / 2;
    pair<ii, int> a = query(x, y, id * 2, l, mid);
    pair<ii, int> b = query(x, y, id * 2 + 1, mid, r);
    return merge(a, b);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#endif
	scanf("%s%d", str, &q);
    n = strlen(str);
    build();
    while(q--){
        int l, r;
        scanf("%d%d", &l, &r);
        printf("%d\n", 2 * query(l - 1, r).S);
    }
    return 0;
}