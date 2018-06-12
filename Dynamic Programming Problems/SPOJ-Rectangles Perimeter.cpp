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

const db eps = 1e-12;
const db pi = acos(-1);
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const int mod = 1000 * 1000 * 1000 + 7;

int n;
int arr[2][1005];
int dp[1005][2];

int solve(int i, int f){
    if(i > n) return 0;
    int &ret = dp[i][f];
    if(~ret) return ret;
    ret = solve(i + 1, 0) + (i > 1) * abs(arr[f][i - 1] - arr[0][i]) + arr[1][i];
    ret = max(ret ,solve(i + 1, 1) + (i > 1) * abs(arr[f][i - 1] - arr[1][i]) + arr[0][i]);
    return ret;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    sf(n);
    for(int i = 1; i <= n; ++i)
        sf(arr[0][i]), sf(arr[1][i]);
    memset(dp, -1, sizeof dp);
    printf("%d\n", solve(1, 0));
    return 0;
}
