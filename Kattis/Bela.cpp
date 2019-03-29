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

int n, ans;
char s, a, b;
map<char, int> value[2];

void init() {
    value[0]['A'] = 11;
    value[1]['A'] = 11;
    value[0]['K'] = 4;
    value[1]['K'] = 4;
    value[0]['Q'] = 3;
    value[1]['Q'] = 3;
    value[0]['J'] = 20;
    value[1]['J'] = 2;
    value[0]['T'] = 10;
    value[1]['T'] = 10;
    value[0]['9'] = 14;
    value[1]['9'] = 0;
    value[0]['8'] = 0;
    value[1]['8'] = 0;
    value[0]['7'] = 0;
    value[1]['7'] = 0;

}

int main() {
    init();
    cin >> n >> s;
    for (int i = 0; i < (n << 2); ++i) {
        cin >> a >> b;
        ans += value[b != s][a];
    }
    cout << ans << endl;
    return 0;
}
