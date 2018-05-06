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
ll S;
pair<int, ll> a[27];
int pwr3[11];
// dp[ 3 ^ 13 + 100]
ll dp[1594323 + 5][11];
map<ll, ll> mp[26];

ll getFac(int x){
    if(x > 20)
        return 10000000000000005LL;
    ll res = 1;
    for(int i = 1; i <= x; ++i)
        res *= i;
    return res;
}

ll solve(int mask, int st, ll curSum, int usd){
    if(st == min(n, 11)){
        if(curSum > S) return 0;
        ll res = 0;
        for(int tmp = 0; tmp <= k - usd; ++tmp)
            if(mp[tmp].count(S- curSum))
                res += mp[tmp][S - curSum];
        return res;
    }
    ll &ret = dp[mask][st];
    if(~ret) return ret;
    ret = solve(mask, st + 1, curSum, usd);
    ret += solve(mask + pwr3[st] * 1, st + 1, curSum + a[st].F, usd);
    ret += solve(mask + pwr3[st] * 2, st + 1, curSum + a[st].S, usd + 1);
    return ret;
}

void solve2(int st, ll curSum, int usd){
    if(11 + st >= n){
        mp[usd][curSum]++;
        return;
    }
    solve2(st + 1, curSum, usd);
    solve2(st + 1, curSum + a[11 + st].F, usd);
    solve2(st + 1, curSum + a[11 + st].S, usd + 1);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    cin >> n >> k >> S;
    for(int i = 0; i < n; ++i){
        scanf("%d", &a[i].F);
        a[i].S = getFac(a[i].F);
    }
    pwr3[0] = 1;
    for(int i = 1; i <= 11; ++i)
        pwr3[i] = pwr3[i - 1] * 3;
    memset(dp, -1, sizeof dp);
    solve2(0, 0, 0);
    printf("%lld\n", solve(0, 0, 0, 0));
    return 0;
}