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

int T;
int m;

vector<int> primes;
bool isPrime[1000005];

void sieve() {
    isPrime[0] = isPrime[1] = 1;
    for (int i = 2; i < 1000005; ++i) {
        if (!isPrime[i]) {
            primes.push_back(i);
            for (ll j = i *1LL * i; j < 1000005; j += i)
                isPrime[j] = 1;
        }
    }
}

ll eulerPhi(int N) {
    ll PF_idx = 0, PF = primes[PF_idx], ans = N;
    while (PF * PF <= N) {
        if (N % PF == 0 ) ans -= ans / PF;
        while (N % PF == 0) N /= PF;
        PF = primes[++PF_idx];
    }
    if (N != 1) ans -= ans / N;
    return ans;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    sieve();
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &m);
        printf("%lld\n", (m - 1) * eulerPhi(m));
    }
    return 0;
}
