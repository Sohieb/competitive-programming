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
int n;
pair<pii, pii> arr[100005];
int ans[100005];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d%d", &arr[i].F.S, &arr[i].F.F);
            arr[i].S.F = INF;
            arr[i].S.S = i;
        }
        sort(arr, arr + n);
        arr[n - 1].S.F = arr[n - 1].F.S;
        for (int i = n - 2; i >= 0; --i) {
            arr[i].S.F = min(arr[i + 1].S.F, arr[i].F.S);
        }
        bool can = 0;
        for (int i = 0; i < n; ++i) {
            if (arr[i + 1].S.F <= arr[i].F.F) continue;
            can = 1;
            for (int j = 0; j < n; ++j) {
                if (j <= i) {
                    ans[arr[j].S.S] = 1;
                } else {
                    ans[arr[j].S.S] = 2;
                }
            }
            for (int j = 0; j < n; ++j)
                printf("%d%c", ans[j], " \n"[j==n-1]);
            break;
        }
        if (can == 0) 
            printf("-1\n");
    }
    return 0;
}