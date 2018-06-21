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

const db eps = 1e-12;
const db pi = acos(-1);
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const int mod = 1000 * 1000 * 1000 + 7;

ll x, k;

ll pwr(ll base, ll pw){
    base %= mod;
    ll res = 1;
    while(pw){
        if(pw % 2) res = res * base % mod;
        base = base * base % mod;
        pw /= 2;
    }
    return res;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    cin >> x >> k;
    if(x == 0) return !printf("0\n");
    x *= 2;
    ll tw = pwr(2, k);
    int res = (tw * (x % mod) - tw + 1 + mod) % mod;
    cout << res << endl;
    return 0;
}
