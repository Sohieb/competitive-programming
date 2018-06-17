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

int n, m;
char str[300005];
vector<int> adj[300005];
int col[300005];
int dp[26][300005];

bool dfsCyc(int u){
    if(col[u] == -1) return 1;
    col[u] = -1;
    for(int i = 0; i < sz(adj[u]); ++i){
        if(col[adj[u][i]] == 1) continue;
        if(dfsCyc(adj[u][i])) return 1;
    }
    col[u] = 1;
    return 0;
}

int solve(int c,int u){
    int &ret = dp[c][u];
    if(~ret) return ret;
    ret = 0;
    for(int i = 0; i < sz(adj[u]); ++i)
        ret = max(ret, solve(c, adj[u][i]));
    ret += (str[u - 1] - 'a' == c);
    return ret;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    scanf("%d%d%s", &n, &m, str);
    for(int i = 0; i < m; ++i){
        int u, v;
        sf(u), sf(v);
        adj[u].push_back(v);
    }
    for(int i = 1; i <= n; ++i){
        if(col[i]) continue;
        if(dfsCyc(i))
            return !printf("-1\n");
    }
    int out = 0;
    memset(dp, -1, sizeof dp);
    for(int j = 0; j < 26; ++j)
        for(int i = 1; i <= n; ++i)
            out = max(out, solve(j, i));
    printf("%d\n", out);
    return 0;
}
