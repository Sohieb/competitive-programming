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

string str;
int dp[200005][4][2];

int solve(int i = 0, int sm = 0, int flag = 0) {
    if(i == sz(str)) return !sm;
    int &ret = dp[i][sm][flag];
    if(~ret) return ret;
    ret = solve(i + 1, (sm + str[i] - '0') % 3, 1);
    if(flag)
        ret = max(ret, solve(i + 1, (str[i] - '0') % 3, 1) + !sm);
    return ret;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    cin >> str;
    memset(dp, -1, sizeof dp);
    cout << solve() << endl;
    return 0;
}
