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
pair<int, int> arr[200200];
int vis[200200];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d%d", &arr[i].F, &arr[i].S);
    }
    vector<int> ans;
    int me = 1;
    while (sz(ans) < n) {
        vis[me] = 1;
        ans.push_back(me);
        int a = arr[me].F, b = arr[me].S;
        if (arr[a].F == b || arr[a].S == b && vis[a] == 0) {
            me = a;
        } else {
            me = b;
        }
    }
    for (int i = 0; i < n; ++i)
        printf("%d%c", ans[i], " \n"[i==n-1]);
    return 0;
}
