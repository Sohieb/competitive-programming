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
string a, b;
string zero = "0000000000000000000000000000000";

int main() {
    scanf("%d", &T);
    for (int C = 1; C <= T; ++C) {
        cin >> a >> b;
        cout << a << " " << b << endl;
        while (a != zero && b != zero) {
            string c = a, d = b;
            for (int i = 0; i < sz(a); ++i) {
                c[i] = (a[i] == b[i] ? '0' : '1');
                d[i] = (a[i] + b[i] - '0' - '0' == 2 ? '1' : '0');
            }
            a = c, b = d;
            b += "0";
            cout << a << " ";
            if (b[0] == '1') {
                cout << "overflow\n";
                break;
            } else {
                b = b.substr(1);
                cout << b << endl;
            }
        }
        if (T - C) cout << endl;
    }
    return 0;
}
