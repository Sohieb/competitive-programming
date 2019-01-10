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
char str[300005];
int cnt[3];
int rem[3];

int main() {
    scanf("%d%s", &n, str);
    for (int i = 0; str[i]; ++i)
        if (str[i] == '0') ++cnt[0];
        else if (str[i] == '1') ++cnt[1];
        else ++cnt[2];
    rem[0] = cnt[0], rem[1] = cnt[1], rem[2] = cnt[2];
    int need = n / 3;
    for (int i = 0; str[i]; ++i) {
        int me = str[i] - '0';
        rem[me]--;
        if (cnt[me] <= need) continue;
        if (me == 0) {
            if (rem[0] >= cnt[me] - need) continue;
            if (cnt[1] < need) {
                str[i] = '1';
                cnt[1]++;
                cnt[0]--;
            } else {
                str[i] = '2';
                cnt[2]++;
                cnt[0]--;
            }
        } else if (me == 1) {
            if (cnt[0] < need) {
                str[i] = '0';
                cnt[0]++;
                cnt[1]--;
            } else {
                if (rem[1] >= cnt[me] - need) continue;
                str[i] = '2';
                cnt[2]++;
                cnt[1]--;
            }
        } else {
            if (cnt[0] < need) {
                str[i] = '0';
                cnt[0]++;
                cnt[2]--;
            } else {
                str[i] = '1';
                cnt[1]++;
                cnt[2]--;
            }
        }
    }
    printf("%s\n", str);
    return 0;
}
