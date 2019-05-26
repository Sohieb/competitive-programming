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
int n, m, k;
int arr[303][303];
int logV[100100];

int spMin[303][303][17],spMax[303][303][17];

void spBuild(int z){
    for(int i = 0; i <= m; ++i)
        logV[i] = log2(i);
    for(int i = 1; i <= m; ++i)
        spMin[z][i][0] = spMax[z][i][0] = arr[z][i];

    for(int j = 1; (1 << j) <= m; ++j)
        for(int i = 1; i + (1 << j) <= m + 1; ++i){
            spMin[z][i][j] = min(spMin[z][i][j-1], spMin[z][i+(1<<(j-1))][j-1]);
            spMax[z][i][j] = max(spMax[z][i][j-1], spMax[z][i+(1<<(j-1))][j-1]);
        }
}

int getMn(int z, int l, int r){
    int lg = logV[r-l+1];
    return min(spMin[z][l][lg], spMin[z][r-(1<<lg)+1][lg]);
}

int getMx(int z, int l, int r){
    int lg = logV[r-l+1];
    return max(spMax[z][l][lg], spMax[z][r-(1<<lg)+1][lg]);
}

int main() {
    scanf("%d", &T);
    for (int C = 1; C <= T; ++C) {
        memset(spMin, 0, sizeof spMin);
        memset(spMax, 0, sizeof spMax);
        scanf("%d%d%d", &n, &m, &k);
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j)
                scanf("%d", &arr[i][j]);
            spBuild(i);
        }
        int ans = 0;
        for (int i = 1; i <= m; ++i)
            for (int j = i; j <= m; ++j) {
                vector<int> v;
                for (int w = 1; w <= n; ++w) {
                    pii q;
                    q.F = getMn(w, i, j);
                    q.S = getMx(w, i, j);
                    // cout << i << " " << j << " " << q.F << " " << q.S << endl;
                    if (q.S - q.F <= k)
                        v.push_back(1);
                    else
                        v.push_back(0);
                }
                int mxSum = 0, cur = 0;
                for (int w = 0; w < n; ++w) {
                    cur += v[w];
                    mxSum = max(mxSum, cur);
                    if (v[w] == 0) cur = 0;
                }
                ans = max(ans, mxSum * (j - i + 1));
            }
        printf("Case #%d: %d\n", C, ans);
    }
    return 0;
}
