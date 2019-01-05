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
int a[3] = {1, 0, 0};

int main() {
    cin >> str;
    for (int i = 0; i < sz(str); ++i) {
        if (str[i] == 'A') {
            swap(a[0], a[1]);
        } else if (str[i] == 'B') {
            swap(a[2], a[1]);
        } else {
            swap(a[0], a[2]);
        }
    }
    for (int i = 0; i < 3; ++i)
        if (a[i]) cout << (i + 1) << endl;
    return 0;
}
