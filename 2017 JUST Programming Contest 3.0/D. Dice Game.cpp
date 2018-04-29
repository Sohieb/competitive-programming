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
int sum;
vector<int> adj[10];

void init(){
    adj[1].push_back(2);
    adj[1].push_back(3);
    adj[1].push_back(4);
    adj[1].push_back(5);

    adj[2].push_back(1);
    adj[2].push_back(3);
    adj[2].push_back(4);
    adj[2].push_back(6);

    adj[3].push_back(1);
    adj[3].push_back(2);
    adj[3].push_back(5);
    adj[3].push_back(6);

    adj[4].push_back(1);
    adj[4].push_back(2);
    adj[4].push_back(5);
    adj[4].push_back(6);

    adj[5].push_back(1);
    adj[5].push_back(3);
    adj[5].push_back(4);
    adj[5].push_back(6);

    adj[6].push_back(2);
    adj[6].push_back(3);
    adj[6].push_back(4);
    adj[6].push_back(5);
}

int dp[10005][7];

int solve(int rem, int tp){
    if(rem < 0) return INF;
    if(rem == 0) return ((tp == 1)? 0 : INF);
    int &ret = dp[rem][tp];
    if(~ret) return ret;
    ret = INF;
    for(int i = 0; i < sz(adj[tp]); ++i){
        ret = min(ret, 1 + solve(rem - tp, adj[tp][i]));
    }
    return ret;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    init();
    scanf("%d", &T);
    memset(dp, -1, sizeof dp);
    while(T--){
        scanf("%d", &sum);
        int ans = INF;
        for(int i = 1; i < 7; ++i)
            ans = min(ans, solve(sum, i));
        if(ans > 10000) puts("-1");
        else printf("%d\n", ans);
    }
    return 0;
}