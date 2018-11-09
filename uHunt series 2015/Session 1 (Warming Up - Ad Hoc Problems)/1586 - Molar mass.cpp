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
string str;
map<char, double> w;

void init() {
    w['C'] = 12.01;
    w['H'] = 1.008;
    w['O'] = 16.00;
    w['N'] = 14.01;
    w['#'] = 0;
}

int main() {
    init();
    scanf("%d", &T);
    char c, me;
    int cnt = 0;
    while (T--) {
        cin >> str;
        double out = 0;
        me = '#';
        cnt = 0;
        for (int i = 0; i < sz(str); ++i) {
            c = str[i];
            if (isdigit(c)) {
                cnt = cnt * 10 + (c - '0');
            } else {
                out += max(cnt, 1) * w[me];
                me = c;
                cnt = 0;
            }
        }
        out += max(cnt, 1) * w[me];
        printf("%.3f\n", out);
    }
    return 0;
}
