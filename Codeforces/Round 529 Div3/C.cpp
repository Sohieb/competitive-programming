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

int n, k;

int ones(int x) {
    return (x == 0 ? 0 : ones(x / 2) + x % 2);
}

int main() {
    cin >> n >> k;
    if (k > n) return !printf("NO\n");
    if (ones(n) > k) return !printf("NO\n");
    priority_queue<int> pq;
    for (int i = 0; i < 30; ++i) {
        if ((n & (1 << i)) != 0)
            pq.push(1 << i);
    }
    while (sz(pq) < k) {
        int me = pq.top();
        pq.pop();
        pq.push(me / 2);
        pq.push(me / 2);
    }
    cout << "YES\n";
    while (!pq.empty()) {
        printf("%d%c", pq.top(), " \n"[sz(pq) == 1]);
        pq.pop();
    }
    return 0;
}
