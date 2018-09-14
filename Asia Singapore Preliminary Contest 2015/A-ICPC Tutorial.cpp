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

int m, n, t;

int main() {
    cin >> m >> n >> t;
    ll cnt;
    double nlg;
    switch (t) {
        case 1:
            if (n > 13) return !printf("TLE\n");
            cnt = 1;
            for (int i = 1; i <= n; ++i) cnt *= i;
            printf(cnt <= m ? "AC\n" : "TLE\n");
            break;
        case 2:
            if (n > 30) return !printf("TLE\n");
            cnt = 1;
            for (int i = 1; i <= n; ++i) cnt *= 2;
            printf(cnt <= m ? "AC\n" : "TLE\n");
            break;
        case 3:
            if (n > 200) return !printf("TLE\n");
            cnt = n * n * n * n;
            printf(cnt <= m ? "AC\n" : "TLE\n");
            break;
        case 4:
            if (n > 1000) return !printf("TLE\n");
            cnt = n * n * n;
            printf(cnt <= m ? "AC\n" : "TLE\n");
            break;
        case 5:
            if (n > 10000) return !printf("TLE\n");
            cnt = n * n;
            printf(cnt <= m ? "AC\n" : "TLE\n");
            break;
        case 6:
            nlg = n * log2(n) + eps;
            printf(nlg <= m ? "AC\n" : "TLE\n");
            break;
        case 7:
            printf(n <= m ? "AC\n" : "TLE\n");
            break;
    }
    return 0;
}
