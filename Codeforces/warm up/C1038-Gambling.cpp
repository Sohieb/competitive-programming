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
int a[100005], b[100005];
ll sum1, sum2;

int main() {
    scanf("%d", &n);
    for (int i = 0 ; i < n; ++i)
        scanf("%d", a + i);
    for (int i = 0 ; i < n; ++i)
        scanf("%d", b + i);
    sort(a, a + n, greater<int>());
    sort(b, b + n, greater<int>());
    int turn = 0, i = 0, j = 0;
    while (i < n || j < n) {
        turn ^= 1;
        if (turn == 1) {
            if (i == n) {
                ++j;
                continue;
            }
            if (j == n) {
                sum1 += a[i++];
                continue;
            }
            if (a[i] >= b[j])
                sum1 += a[i++];
            else ++j;
        } else {
            if (j == n) {
                ++i;
                continue;
            }
            if (i == n) {
                sum2 += b[j++];
                continue;
            }
            if (b[j] >= a[i])
                sum2 += b[j++];
            else ++i;
        }
    }
    cout << (sum1 - sum2) << endl;
    return 0;
}