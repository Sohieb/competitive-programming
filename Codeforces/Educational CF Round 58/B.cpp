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

char s[500005];
string str;

int main() {
    scanf("%s", s);
    str = s;
    int a = -1, b = -1;
    for (int i = 0; i < sz(str); ++i) {
        if (str[i] == '[') {
            a = i;
            break;
        }
    }
    if (a == -1) return !printf("%d\n", -1);
    str = str.substr(a);
    a = 0;
    for (int i = sz(str) - 1; i > a; --i) {
        if (str[i] == ']') {
            b = i;
            break;
        }
    }
    if (b == -1) return !printf("%d\n", -1);
    str = str.substr(a, b - a + 1);
    b = sz(str) - 1;
    int ans = 2;
    for (int i = 0; i < sz(str); ++i) {
        if (str[i] == ':') {
            a = i;
            break;
        }
    }
    if (a == 0) return !printf("%d\n", -1);
    for (int i = sz(str) - 1; i > a; --i) {
        if (str[i] == ':') {
            b = i;
            break;
        }
    }
    if (b == sz(str) - 1) return !printf("%d\n", -1);
    //cout << str << endl << a << " " << b << endl;
    ans  = 4;
    for (int i = a; i <= b; ++i) {
       // cout << str[i];
        if (str[i] == '|') ++ans;
    }
   // cout << endl;
    cout << ans << endl;
    return 0;
}