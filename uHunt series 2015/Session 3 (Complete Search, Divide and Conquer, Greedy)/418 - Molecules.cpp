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

string arr[4];

int main() {
    while(cin >> arr[0]) {
        if (sz(arr[0]) == 1)
            break;
        cin >> arr[1] >> arr[2] >> arr[3];
        sort(arr, arr + 4);
        int ans = 0;
        do {
            for (int i = 1; i < 11; ++i)
                for (int j = i + 2; j < 11; ++j) {
                    int len1 = j - i;
                    for (int k = 1; k + len1 < 11; ++k)
                        for (int ii = 1; ii < 11; ++ii)
                            for (int jj = ii + 2; jj < 11; ++jj) {
                                int len2 = jj - ii;
                                for (int kk = 1; kk + len2 < 11; ++kk) {
                                    if (arr[0][i] != arr[2][ii]) continue;
                                    if (arr[0][j] != arr[3][kk]) continue;
                                    if (arr[1][k] != arr[2][jj]) continue;
                                    if (arr[1][k + len1] != arr[3][kk + len2]) continue;
                                    ans = max(ans, (len1 - 1) * (len2 - 1));
                                }
                            }
            }
        }while(next_permutation(arr, arr + 4));
        printf("%d\n", ans);
    }
    return 0;
}
