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

int a, b, x;
int dp[101][101][202][3];

int solve(int z, int o, int d, int lst) {
    if (z > a) return 0;
    if (o > b) return 0;
    if (d > x) return 0;
    if (z == a && o == b) return (d == x);
    int &ret = dp[z][o][d][lst];
    if (~ret) return ret;
    ret = solve(z + 1, o, d + (lst == 1), 0);
    ret |= solve(z, o + 1, d + (lst == 0), 1);
    return ret;
}

void printAns(int z, int o, int d, int lst) {
    if (z == a && o == b) return;
    int &ret = dp[z][o][d][lst];
    if (ret == solve(z + 1, o, d + (lst == 1), 0)) {
        printf("0");
        printAns(z + 1, o, d + (lst == 1), 0);
    } else {
        printf("1");
        printAns(z, o + 1, d + (lst == 0), 1);
    }
    return;
}

int main() {
    cin >> a >> b >> x;
    memset(dp, -1, sizeof dp);
    solve(0, 0, 0, 2);
    printAns(0, 0, 0, 2);
    printf("\n");
    return 0;
}