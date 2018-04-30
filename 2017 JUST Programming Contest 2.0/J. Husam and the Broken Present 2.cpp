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

int n;
vector<int> arr[20];
int dp1[20][20];
int dp2[16][(1<<16) + 5];
int bad[20];

int pre(){
    //memset(dp1, 0x3f, sizeof dp1);
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j){
            if(i == j) continue;
            for(int k = 0; k <= min(sz(arr[i]), sz(arr[j])); ++k){
                int x = sz(arr[i]) - k;
                int y = 0;
                bool can = 1;
                while(x < sz(arr[i]) && y < sz(arr[j]))
                    if(arr[i][x++] != arr[j][y++])
                        can = 0;
                if(can) dp1[i][j] = k;
            }
            for(int k = 0; k < sz(arr[i]); ++k){
                int cur = 0;
                for(int w = 0; w < sz(arr[j]); ++w)
                    if(k + w < sz(arr[i]) && arr[i][k + w] == arr[j][w])
                        ++cur;
                if(cur == sz(arr[j])) bad[j] = 1;
            }
        }
}

int solve(int mask, int lst){
    if(mask == (1 << n) - 1)
        return 0;
    int &ret = dp2[lst][mask];
    if(~ret) return ret;
    ret = INF;
    for(int i = 0 ; i < n; ++i){
        if(mask & (1 << i))
            continue;
        ret = min(ret, solve((mask | (1 << i)), i) + sz(arr[i]) - dp1[lst][i]);
    }
    return ret;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    scanf("%d", &n);
    for(int i = 0; i < n; ++i){
        int x;
        cin >> x;
        arr[i].resize(x);
        for(int j = 0; j < x; ++j)
            scanf("%d", &arr[i][j]);
    }
    pre();
    int mask1 = 0;
    for(int i = 0; i < n; ++i)
        if(bad[i])
            mask1 = (mask1 | (1 << i));
    int out = INF;
    memset(dp2, -1, sizeof dp2);
    for(int i = 0; i < n; ++i){
        out = min(out, sz(arr[i]) + solve(mask1 | (1 << i), i));
    }
    printf("%d\n", out);
    return 0;
}