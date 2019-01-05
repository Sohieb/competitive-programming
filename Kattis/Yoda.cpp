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

string s1, s2;

int main() {
    cin >> s1 >> s2;
    while (sz(s1) < sz(s2))
        s1 = "0" + s1;
    while (sz(s2) < sz(s1))
        s2 = "0" + s2;
    for (int i = 0; i < sz(s1); ++i) {
        if (s1[i] == s2[i]) continue;
        if (s1[i] < s2[i]) s1[i] = '#';
        else s2[i] = '#';
    }
    while (s1.find('#') != -1)
        s1.erase(s1.begin() + s1.find('#'));
    while (s2.find('#') != -1)
        s2.erase(s2.begin() + s2.find('#'));
    if (count(all(s1), '0') == sz(s1) && sz(s1)) s1 = "0";
    if (count(all(s2), '0') == sz(s2) && sz(s2)) s2 = "0";
    if (sz(s1) == 0) s1 = "YODA";
    if (sz(s2) == 0) s2 = "YODA";
    cout << s1 << endl << s2 << endl;
    return 0;
}
