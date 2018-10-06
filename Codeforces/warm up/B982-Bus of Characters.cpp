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

int n, w;
char str[400005];

int main() {
    scanf("%d", &n);
    set<pair<int,int> > in, ex;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &w);
        in.insert({w, i});
    }
    scanf("%s", str);
    for (int i = 0; str[i]; ++i) {
        pair<int,int> me;
        if (str[i] == '0') {
            me = *in.begin();
            in.erase(me);
            ex.insert(me);
        } else {
            me = *ex.rbegin();
            ex.erase(me);
        }
        printf("%d%c", me.S, " \n"[str[i+1]==0]);
    }
    return 0;
}
