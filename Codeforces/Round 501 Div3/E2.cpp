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

int n, m;
char arr[1010][1010];
int row[1010][1010];
int col[1010][1010];
int comR[1010][1010];
int comC[1010][1010];

bool ok(int i, int j, int len){
    if(len == 0) return 1;
    if(i - len < 1) return 0;
    if(j - len < 1) return 0;
    if(i + len > n) return 0;
    if(j + len > m) return 0;
    if(col[i][j - 1] - col[i][j - len - 1] < len)
        return 0;
    if(col[i][j + len] - col[i][j] < len)
        return 0;
    if(row[i - 1][j] - row[i - len - 1][j] < len)
        return 0;
    if(row[i + len][j] - row[i][j] < len)
        return 0;
    return 1;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j){
            scanf(" %c", &arr[i][j]);
            row[i][j] = col[i][j] = arr[i][j] == '*';
        }
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            col[i][j] += col[i][j - 1];
    for(int j = 1; j <= m; ++j)
        for(int i = 1; i <= n; ++i)
            row[i][j] += row[i - 1][j];
    vector<pair<pii,int> > ans;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            if(arr[i][j] == '.')
                continue;
            int l = 0, r = n, mid;
            while(l < r){
                mid = l + (r - l + 1) / 2;
                if(ok(i, j, mid)) l = mid;
                else r = mid - 1;
            }
            if(l == 0)
                continue;
            ans.push_back({{i, j}, l});
            comR[i - l][j] += 1;
            comR[i + l + 1][j] -= 1;
            comC[i][j - l] += 1;
            comC[i][j + l + 1] -= 1;
        }
    }
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            comC[i][j] += comC[i][j - 1];
    for(int j = 1; j <= m; ++j)
        for(int i = 1; i <= n; ++i)
            comR[i][j] += comR[i - 1][j];
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            if(arr[i][j] == '*' && comR[i][j] + comC[i][j] == 0)
                return !printf("%d\n", -1);
    printf("%d\n", sz(ans));
    for(int i = 0; i < sz(ans); ++i)
        printf("%d %d %d\n", ans[i].F.F, ans[i].F.S, ans[i].S);
    return 0;
}
