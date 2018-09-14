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

int T;
int n, m;
char str[100005];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d%s", &n, &m, str);
        int goodCnt = 0;
        for (int i = 0; i < n / 2; ++i) 
            goodCnt += (str[i] == str[n - i - 1]);
        int ans = 0;
        char c;
        int p;
        while (m--) {
            scanf("%d %c", &p, &c);
            --p;
            if (str[p] == str[n - p - 1]) --goodCnt;
            str[p] = c;
            if (str[p] == str[n - p - 1]) ++goodCnt;
            ans += (goodCnt == n / 2);
        }
        printf("%d\n", ans);
    }
    return 0;
}
