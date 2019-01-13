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
string str, ans1, ans2;

int main() {
    cin >> n >> str;
    int r = count(all(str), 'r');
    int b = count(all(str), 'b');
    for (int i = 0; i < n; ++i) 
        if (i % 2)
            ans1 += 'r', ans2 += 'b';
        else
            ans1 += 'b', ans2 += 'r';
    int needr = 0, needb = 0;
    int ch1 = 0;
    for (int i = 0; i < n; ++i) {
        if (ans1[i] == str[i]) continue;
        if (ans1[i] == 'r') {
            if (needb) ++ch1, --needb;
            else ++needr;
        } else {
            if (needr) ++ch1, --needr;
            else ++needb;
        }
    }
    ch1 += needb + needr;
    needr = 0, needb = 0;
    int ch2 = 0;
    for (int i = 0; i < n; ++i) {
        if (ans2[i] == str[i]) continue;
        if (ans2[i] == 'r') {
            if (needb) ++ch2, --needb;
            else ++needr;
        } else {
            if (needr) ++ch2, --needr;
            else ++needb;
        }
    }
    ch2 += needb + needr;
    cout << min(ch1, ch2) << endl;
    return 0;
}
