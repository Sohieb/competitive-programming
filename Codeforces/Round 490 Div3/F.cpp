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

int n, k;
int arr[50005];
int f[505];
int h[12];
int cntF[100005];
int dp[505][5005];

int solve(int i, int rem){
    if(i == 0) return 0;
    int &ret = dp[i][rem];
    if(~ret) return ret;
    for(int j = 0; j <= min(k, rem); ++j)
        ret = max(ret, solve(i - 1, rem - j) + h[j]);
    return ret;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    sf(n), sf(k);
    for(int i = 0; i < n * k; ++i)
        sf(arr[i]);
    for(int i = 0; i < n; ++i)
        sf(f[i]), cntF[f[i]]++;
    for(int i = 1; i <= k; ++i)
        sf(h[i]);
    ll ans = 0;
    memset(dp, -1, sizeof dp);
    for(int i = 1; i < 100001; ++i){
        if(cntF[i] == 0) continue;
        int can = count(arr, arr + n * k, i);
        ans += solve(cntF[i], can);
    }
    printf("%lld\n", ans);
    return 0;
}
