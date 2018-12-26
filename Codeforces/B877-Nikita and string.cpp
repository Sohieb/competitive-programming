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

string str;
int cntA[5050];
int cntB[5050];

int main() {
    cin >> str;
    cntA[0] = str[0] == 'a';
    cntB[0] = str[0] == 'b';
    for (int i = 1; i < sz(str); ++i) {
        cntA[i] = cntA[i - 1] + (str[i] == 'a');
        cntB[i] = cntB[i - 1] + (str[i] == 'b');
    }
    int ans = 0;
    if (count(all(str), 'a') == sz(str))
        ans = sz(str);
    if (count(all(str), 'b') == sz(str))
        ans = sz(str);
    for (int i = 0; i < sz(str); ++i) {
        ans = max(ans, sz(str) - cntB[i] - (cntA[sz(str) - 1] - cntA[i]));
        ans = max(ans, sz(str) - cntA[i] - (cntB[sz(str) - 1] - cntB[i]));
    }
    for (int i = 0; i < sz(str); ++i) {
        for (int j = i + 1; j < sz(str); ++j) {
            int tmp = sz(str);
            tmp -= cntB[i];
            tmp -= (cntB[sz(str) - 1] - cntB[j - 1]);
            tmp -= (cntA[j - 1] - cntA[i]);
            ans = max(ans, tmp);
        }
    }
    cout << ans << endl;
    return 0;
}
