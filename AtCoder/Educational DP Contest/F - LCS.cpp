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
char s[3030], t[3030];
int dp[3003][3003];

int solve(int i, int j) {
    if (i == n || j == m) return 0;
    int &ret = dp[i][j];
    if (~ret) return ret;
    ret = max(solve(i + 1, j), solve(i, j + 1));
    if (s[i] == t[j]) ret = max(ret, solve(i + 1, j + 1) + 1);
    return ret;
}

void printAns(int i, int j) {
    if (i == n || j == m) return;
    int &ret = dp[i][j];
    if (ret == solve(i + 1, j)) {
        printAns(i + 1, j);
    } else if (ret == solve(i, j + 1)) {
        printAns(i, j + 1);
    } else {
        printf("%c", s[i]);
        printAns(i + 1, j + 1);
    }
    return;
}

int main() {
    scanf("%s%s", s, t);
    n = strlen(s);
    m = strlen(t);
    memset(dp, -1, sizeof dp);
    solve(0, 0);
    printAns(0, 0);
    cout << endl;
    return 0;
}
