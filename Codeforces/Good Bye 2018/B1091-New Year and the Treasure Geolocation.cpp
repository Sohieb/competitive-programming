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
pair<int, int> a[1010];
pair<int, int> b[1010];

map<pair<int,int>, int> mp;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &a[i].F, &a[i].S);
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &b[i].F, &b[i].S);
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            mp[{a[i].F + b[j].F, a[i].S + b[j].S}]++;
        }
    }
    for (auto it : mp) {
        if (it.S >= n) {
            cout << it.F.F << " " << it.F.S << endl;
            return 0;
        }
    }
    return 0;
}
