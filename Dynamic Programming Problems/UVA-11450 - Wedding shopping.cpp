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
int S, n;
vector<int> arr[22];
int dp[22][202];

int solve(int i, int rem){
    if(rem < 0) return INF;
    if(i == n) return rem;
    int &ret = dp[i][rem];
    if(~ret) return ret;
    ret = INF;
    for(int j = 0; j < sz(arr[i]); ++j)
        ret = min(ret, solve(i + 1, rem - arr[i][j]));
    return ret;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    sf(T);
    while(T--){
        for(int i = 0; i < 20; ++i)
            arr[i].clear();
        sf(S), sf(n);
        for(int i = 0; i < n; ++i){
            int k, x;
            sf(k);
            for(int j = 0; j < k; ++j)
                sf(x), arr[i].push_back(x);
        }
        memset(dp, -1, sizeof dp);
        int minRem = solve(0, S);
        if(minRem <= S)
            printf("%d\n", S - minRem);
        else
            printf("no solution\n");
    }
    return 0;
}
