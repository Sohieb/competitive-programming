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

int T;
int n;
int arr[1005];
int dp[1005][1005];

int solve(int i, int j){
    if(i > j) return 0;
    int &ret = dp[i][j];
    if(~ret) return ret;
    ret = max(arr[i] - solve(i + 1, j), arr[j] - solve(i, j - 1));
    return ret;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    sf(T);
    while(T--){
        sf(n);
        for(int i = 0; i < n; ++i)
            sf(arr[i]);
        memset(dp, -1, sizeof dp);
        printf("%d\n", solve(0, n - 1));
    }
    return 0;
}