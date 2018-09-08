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

vector<int> myNum;

int conv(string s) {
    int res = 0;
    reverse(all(s));
    for (int i = 0; i < sz(s); ++i)
        res += (1 << i) * (s[i] == '1');
    return res;
}

void init(string s = "1") {
    if (sz(s) > 25) return;
    myNum.push_back(conv(s));
    init("1" + s + "0");
}

int n;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    init();
    reverse(all(myNum));
    cin >> n;
    for (int i = 0; i < sz(myNum); ++i)
        if (n % myNum[i] == 0)
            return !printf("%d\n", myNum[i]);
    return 0;
}
