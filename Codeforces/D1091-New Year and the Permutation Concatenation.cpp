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
const int mod = 998244353;

int n;
int fac[1000005];
int arr[1000005];

int main() {
    cin >> n;
    fac[0] = 1;
    for (int i = 1; i < 1000005; ++i)
    	fac[i] = (fac[i - 1] * 1LL * i) % mod;
    arr[1] = 1, arr[2] = 2, arr[3] = 9;
    for (int i = 4; i <= n; ++i) {
    	arr[i] = (fac[i] + (arr[i - 1] - 1 + mod) % mod * 1LL * i) % mod;
    }
    cout << arr[n] << endl;
    return 0;
}
