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

int n, t, m;
pair<int, int> pro[12];
int solved[101][12];
int tim, id;
char problem, ver[5];

int main() {
    scanf("%d%d%d", &n, &t, &m);
    for (int i = 0; i < n; ++i)
        pro[i] = {-1, -1};
    for (int i = 0; i < m; ++i) {
        scanf("%d%d %c%s", &tim, &id, &problem, ver);
        if (ver[0] == 'N' || solved[id][problem - 'A'])
            continue;
        solved[id][problem - 'A'] = 1;
        pro[problem - 'A'] = {tim, id};
    }
    for (int i = 0; i < n; ++i) {
        printf("%c ", 'A' + i);
        if (pro[i].F == -1) {
            printf("- -\n");
        } else {
            printf("%d %d\n", pro[i].F, pro[i].S);
        }
    }
    return 0;
}
