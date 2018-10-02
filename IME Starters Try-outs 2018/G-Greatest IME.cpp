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

int n, c;
int fac[300005];

int pwr(int base ,int pw) {
    int ans = 1;
    while (pw) {
        if (pw % 2) ans = ans * 1LL * base % mod;
        base = base * 1LL * base % mod;
        pw /= 2;
    }
    return ans;
}

int nCr(int N, int R) {
    return (fac[N] * 1LL * pwr((fac[R] * 1LL * fac[N - R]) % mod, mod - 2) % mod);
}

int main() {
    fac[0] = 1;
    for (int i = 1; i < 300005; ++i)
        fac[i] = (fac[i - 1] * 1LL * i) % mod;
    cin >> n >> c;
    int N = n + c - 3 * n;
    int res = nCr(N, n);
    res = res * 1LL * fac[n] % mod;
    res = res * 1LL * pwr(6, n) % mod;
    cout << res << endl;
    return 0;
}
