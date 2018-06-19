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

const db eps = 1e-12;
const db pi = acos(-1);
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const int mod = 1000 * 1000 * 1000 + 7;

int l, r, x, y;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    cin >> l >> r >> x >> y;
    if(y % x) return !printf("0\n");
    int d = y / x;
    vector<int> V;
    for(int i = 2; i * i <= d; ++i){
    	if(d % i) continue;
    	int t = 1;
    	while(d % i == 0){
    		t *= i;
    		d /= i;
    	}
    	V.push_back(t);
    }
    if(d > 1) V.push_back(d);
    int ans = 0;
    for(int i = 0; i < (1 << sz(V)); ++i){
    	int v1 = x, v2 = x;
    	for(int j = 0; j < sz(V); ++j){
    		if(i & (1 << j)) v1 *= V[j];
    		else v2 *= V[j];
    	}
    	if(v1 >= l && v1 <= r && v2 >= l && v2 <= r) ++ans;
    }
    printf("%d\n", ans);
    return 0;
}
