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

int n, k;
int arr[1000005];

bool ok(int d) {
    int cnt = 0;
    int canSkp = 0;
    for (int i = 0; i < 2 * n * k; ++i) {
        if (arr[i + 1] - arr[i] <= d) {
            ++cnt;
            ++i;
            canSkp += (k - 1) * 2;
            continue;
        }
        canSkp--;
        if (canSkp < 0) return 0;
    }
    return (cnt >= n);
}

int main() {
    while(scanf("%d%d", &n, &k) != EOF) {
        for (int i = 0; i < 2 * n * k; ++i) 
            scanf("%d", &arr[i]);
        sort(arr, arr + 2 * n * k);
        if (k == 1) {
            int ans = 0;
            for (int i = 0; i < 2 * n; i += 2) 
                ans = max(ans, arr[i + 1] - arr[i]);
            printf("%d\n", ans);
            continue;
        }
        int l = 0, r = 1000000000, mid;
        while (l < r) {
            mid = l + (r - l) / 2;
            if (ok(mid)) r = mid;
            else l = mid + 1;
        }
        printf("%d\n", l);
    }
    return 0;
}
