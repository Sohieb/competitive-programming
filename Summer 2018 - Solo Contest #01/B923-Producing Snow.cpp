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
ll v[100005];
int t[100005];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%lld", v + i);
    for (int i = 0; i < n; ++i)
        scanf("%d", t + i);
    multiset<ll> st;
    ll exT = 0;
    for (int i = 0; i < n; ++i) {
        v[i] += exT;
        st.insert(v[i]);
        ll ans = 0;
        while (!st.empty() && *st.begin() <= t[i] + exT) {
            ans += *st.begin() - exT;
            st.erase(st.begin());
        }
        ans += sz(st) * 1LL * t[i];
        exT += t[i];
        printf("%lld%c", ans, " \n"[i==n-1]);
    }
    return 0;
}
