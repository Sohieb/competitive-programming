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

int arr[10][1000005];

int f(int x) {
    int res = 1;
    while (x) {
        res *= max(1, x % 10);
        x /= 10;
    }
    return res;
}

int g(int x) {
    return (x < 10 ? x : g(f(x)));
}

int q;

int main() {
    for (int i = 1; i < 1000005; ++i) {
        arr[g(i)][i] = 1;
        for (int j = 0; j < 10; ++j)
            arr[j][i] += arr[j][i - 1];
    }
    scanf("%d", &q);
    int l, r, x;
    while (q--) {
        scanf("%d%d%d", &l, &r, &x);
        printf("%d\n", arr[x][r] - arr[x][l - 1]);
    }
    return 0;
}
