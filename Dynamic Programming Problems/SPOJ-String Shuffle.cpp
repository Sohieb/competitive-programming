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

int T, n1, n2, n3;
char s1[62], s2[62], s3[62];
int dp[66][66][66];

int solve(int i, int j, int k){
    if(k == n3) return 1;
    //if(i == n1 || j == n2) return 0;
    int &ret = dp[i][j][k];
    if(~ret) return ret;
    ret = 0;
    for(int x = 0; x < n1 - i; ++x)
        if(s1[i + x] == s3[k])
            ret += solve(i + x + 1, j, k + 1);
    for(int x = 0; x < n2 - j; ++x)
        if(s2[j + x] == s3[k])
            ret += solve(i, j + x + 1, k + 1);
    return ret;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
	sf(T);
    while(T--){
        scanf("%s%s%s", s1, s2, s3);
        n1 = strlen(s1);
        n2 = strlen(s2);
        n3 = strlen(s3);
        memset(dp, -1, sizeof dp);
        printf("%d\n", solve(0, 0, 0));
    }
    return 0;
}
