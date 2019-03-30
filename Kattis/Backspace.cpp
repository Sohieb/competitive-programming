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

char str[1000005];
int nxt[1000005];

int main() {
    scanf("%s", str);
    int n = strlen(str);
    int lst = n, bad = 0;
    for (int i = n - 1; i >= 0; --i) {
        if (str[i] == '<') {
            ++bad;
            continue;
        }
        if (bad) {
            --bad;
            continue;
        }
        nxt[i] = lst;
        lst = i;
    }
    for (int i = lst; i < n; i = nxt[i])
        printf("%c", str[i]);
    cout << endl;
    return 0;
}
