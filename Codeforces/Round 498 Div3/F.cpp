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

int n, m;
ll k, a[22][22];
vector<ll> b[22][22];

void solve1(int i, int j, ll cur, int rem){
    if(rem == 0){
        b[i][j].push_back(cur);
        return;
    }
    if(i + 1 < n)
        solve1(i + 1, j, cur ^ a[i + 1][j], rem - 1);
    if(j + 1 < m)
        solve1(i, j + 1, cur ^ a[i][j + 1], rem - 1);
}

ll solve2(int i, int j, ll cur, int rem){
    if(rem == 0)
        return lower_bound(all(b[i][j]), (cur ^ k) + 1) - 
        lower_bound(all(b[i][j]), cur ^ k);
    cur ^= a[i][j];
    ll ret = 0;
    if(i - 1 >= 0)
        ret += solve2(i - 1, j, cur, rem - 1);
    if(j - 1 >= 0)
        ret += solve2(i, j - 1, cur, rem - 1);
    return ret;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    cin >> n >> m >> k;
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            scanf("%lld", &a[i][j]);
    int stp = n + m - 2;
    solve1(0, 0, a[0][0], (stp + 1) / 2);
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            sort(all(b[i][j]));
    printf("%lld\n", solve2(n - 1, m - 1, 0, stp / 2));
    return 0;
}
