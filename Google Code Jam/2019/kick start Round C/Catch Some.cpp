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

int T;
int n, k;
pii arr[2010];
int cnt[2010];
vector<pii> col[20000];
ll dp[2010][2010][2];
vector<int> myC;

ll solve(int i, int has, int op) {
    if (i == sz(myC)) return (has == k && op ? 0 : 1000000000);
    ll &ret = dp[i][has][op];
    if (~ret) return ret;
    ret = solve(i + 1, has, op);
    for (int j = 0; j < sz(col[myC[i]]); ++j) {
        ret = min(ret, solve(i + 1, has + col[myC[i]][j].S, op) + 2 * col[myC[i]][j].F);
        if (op == 0)
            ret = min(ret, solve(i + 1, has + col[myC[i]][j].S, 1) + col[myC[i]][j].F);
    }
    return ret;
}

void init() {
    memset(dp, -1, sizeof dp);
    memset(cnt, 0, sizeof cnt);
    for (int i = 0; i <= 10000; ++i)
        col[i].clear();
    myC.clear();
}

int main() {
    scanf("%d", &T);
    for (int C = 1; C <= T; ++C) {
        init();
        scanf("%d%d", &n, &k);
        for (int i = 0; i < n; ++i)
            scanf("%d", &arr[i].F);
        for (int i = 0; i < n; ++i)
            scanf("%d", &arr[i].S);
        sort(arr, arr + n);
        for (int i = 0; i < n; ++i) {
            myC.push_back(arr[i].S);
            cnt[arr[i].S]++;
            col[arr[i].S].push_back({arr[i].F, cnt[arr[i].S]});
        }
        sort(all(myC));
        myC.resize(unique(all(myC)) - myC.begin());
        // for (int i = 0; i < sz(myC); ++i) {
        //     cout << myC[i] << " => ";
        //     for (int j = 0; j < sz(col[myC[i]]); ++j)
        //         cout << " { " << col[myC[i]][j].F << ", " << col[myC[i]][j].S << "}";
        //     cout << endl;
        // }
        printf("Case #%d: %lld\n", C, solve(0, 0, 0));
    }
    return 0;
}
