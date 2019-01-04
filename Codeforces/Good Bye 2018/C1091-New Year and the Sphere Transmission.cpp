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

int main() {
    cin >> n;
    vector<ll> v;
    int N, an;
    ll sum;
    for (int i = 1; i * 1LL * i <= n; ++i) {
        if (n % i != 0) continue;
        int j = n / i;
        N = n / i;
        an = 1 + (N - 1) * i;
        sum = N * 1LL * (1 + an) / 2;
        //cout << i << " " << N << " " << an << " " << sum << endl;
        v.push_back(sum);
        if (j != i) {
            N = n / j;
            an = 1 + (N - 1) * j;
            sum = N * 1LL * (1 + an) / 2;
            v.push_back(sum);
        }
    }
    sort(all(v));
    for (int i = 0; i < sz(v); ++i)
        printf("%lld%c", v[i], " \n"[i==sz(v)-1]);
    return 0;
}
