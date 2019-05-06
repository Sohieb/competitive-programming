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

int m, n;
ll t[1005];
ll x[1005];

int main() {
    cin >> m >> n;
    for (int i = 0; i < m; ++i)
        scanf("%lld", &t[i]);
    for (int i = 0; i < n; ++i)
        scanf("%lld", &x[i]);
    vector<ll> ans;
    for (int i = 0; i <= n - m; ++i) {
        set<double> st;
        for (int j = 0; j < m - 1; ++j) {
            st.insert((x[i + j + 1] - x[i + j]) * 1.0 / (t[j + 1] - t[j]));
        }
        if (sz(st) > 1) continue;
        ans.push_back(x[i + 1] - x[i]);
    }
    if (sz(ans)) {
        sort(all(ans));
        ans.resize(unique(all(ans)) - ans.begin());
    }
    cout << sz(ans) << endl;
    for (int i = 0; i < sz(ans); ++i)
        printf("%d%c", ans[i], " \n"[i==sz(ans)-1]);
    return 0;
}