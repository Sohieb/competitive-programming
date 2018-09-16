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
string str;

int dp[222][222][222];

int solve(int i, int j, int k) {
    if (i == n) return (j > k);
    int &ret = dp[i][j][k];
    if (~ret) return ret;
    ret = 0;
    for (char c = 'A'; c <= 'Z'; ++c) {
        ret += solve(i + 1, j + (c == str[j]), k - (c == str[k]));
        if (ret >= mod) ret -= mod;
    }
    return ret;
}

int main() {
    cin >> n >> str;
    memset(dp, -1, sizeof dp);
    printf("%d\n", solve(0, 0, n - 1));
    return 0;
}