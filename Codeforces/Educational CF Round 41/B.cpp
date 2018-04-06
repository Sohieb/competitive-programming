#include <bits/stdc++.h>

using namespace std;
using namespace __gnu_cxx;

typedef double db;
typedef long long ll;
typedef pair<int,int> ii;

#define F        first
#define S        second
#define pnl      printf("\n")
#define sz(x)    (int)x.size()
#define sf(x)    scanf("%d",&x)
#define pf(x)    printf("%d\n",x)
#define all(x)   x.begin(),x.end()
#define rall(x)  x.rbegin(),x.rend()
#define FOR(a,b) for(int i = a; i < b; ++i)

const db eps = 1e-12;
const db pi = acos(-1);
const int inf = 0x3f3f3f3f;
const ll INF = inf * 2LL * inf;
const int mod = 1000 * 1000 * 1000 + 7;

int n, k;
int a[100005];
int t[100005];
int sum[100005];
int dp[100005][2];

int solve(int i, int flag){
    if(i == n) return 0;
    int &ret = dp[i][flag];
    if(~ret) return ret;
    ret = solve(i + 1, flag) + (a[i] * t[i]);
    if(flag == 0){
        int nxt = min(n, i + k);
        ret = max(ret, solve(nxt, 1) 
            + sum[nxt - 1] - (i? sum[i - 1] : 0));
    }
    return ret;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    scanf("%d%d", &n, &k);
    for(int i = 0; i < n; ++i)
        sf(a[i]);
    for(int i = 0; i < n; ++i)
        sf(t[i]);
    sum[0] = a[0];
    for(int i = 1; i < n; ++i)
        sum[i] = sum[i - 1] + a[i];
    memset(dp, -1, sizeof dp);
    cout << solve(0, 0) << endl;
    return 0;
}