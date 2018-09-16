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

string t = "ICPCASIASG";
int n;
string s;
char arr[105][105];
int dp[105][105][12];

int dx[] = {2, 2, 1, 1, -2, -2, -1, -1};
int dy[] = {1, -1, 2, -2, 1, -1, 2, -2};

bool valid(int i, int j) {
    return (i >= 0 && j >= 0 && i < n && j < n);
}

int solve(int i, int j, int k) {
    if (k == 9) return 1;
    int &ret = dp[i][j][k];
    if (~ret) return ret;
    ret = 0;
    for (int c = 0; c < 8; ++c) {
        int ii = i + dx[c];
        int jj = j + dy[c];
        if (!valid(ii, jj)) continue;
        if (arr[ii][jj] != t[k + 1]) continue;
        ret |= solve(ii, jj, k + 1);
    }
    return ret;
}

int main() {
    cin >> n >> s;
    for (int i = 0; i < n * n; ++i) {
        arr[i / n][i % n] = s[i];
    }
    memset(dp, -1, sizeof dp);
    int res = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            if (arr[i][j] != 'I')
                continue;
            res |= solve(i, j, 0);
        }
    printf(res ? "YES\n" : "NO\n");
    return 0;
}