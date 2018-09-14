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
int a[100005];
int b[100005];

int tree[2][100005];

void add(int idx, int x, int v) {
    while (x < 100005) {
        tree[idx][x] += v;
        x += (x & -x);
    }
}

int get(int idx, int x) {
    int sum = 0;
    while (x > 0) {
        sum += tree[idx][x];
        x -= (x & -x);
    }
    return sum;
}

int comp(int x) {
    return 1 + (lower_bound(b, b + n, x) - b);
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", a + i), b[i] = a[i];
    sort(b, b + n);
    for (int i = n - 1; i >= 0; --i)
        add(1, comp(a[i]), 1);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        add(1, comp(a[i]), -1);
        if (get(0, comp(a[i])) == i && get(1, 100000) - get(1, comp(a[i])) == n - i - 1)
            ++ans;
        add(0, comp(a[i]), 1);
    }
    cout << ans << endl;
    return 0;
}
