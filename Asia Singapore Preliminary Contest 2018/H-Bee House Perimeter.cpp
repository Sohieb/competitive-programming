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

int r, k, arr[7500][7500];
int has[7500];
int siz[7500];

int vis[7500][7500];
int outer[7500];

vector<int> cur;
bool isOut;

void dfs(int i, int j) {
    if (i < 1 || i > r + r - 1 || j < 1 || j > siz[i]) return;
    if (vis[i][j]) return;
    if (has[arr[i][j]]) return;
    vis[i][j] = 1;
    cur.push_back(arr[i][j]);
    if (i == 1 || i == r + r - 1 || j == 1 || j == siz[i])
        isOut = 1;
    dfs(i - 1, j);
    dfs(i, j - 1);
    dfs(i + 1, j);
    dfs(i, j + 1);
    if (i < r) {
        dfs(i - 1, j - 1);
        dfs(i + 1, j + 1);
    } else if (i == r) {
        dfs(i - 1, j - 1);
        dfs(i + 1, j - 1);
    } else {
        dfs(i - 1, j + 1);
        dfs(i + 1, j - 1);
    }
}

int main() {
    cin >> r >> k;
    for (int i = 0; i < k; ++i) {
        int dummy;
        scanf("%d", &dummy);
        has[dummy] = 1;
    }
    if (r == 1) 
        return !printf("%d\n", 6);
    siz[1] = r;
    for (int i = 2; i <= r; ++i)
        siz[i] = siz[i - 1] + 1;
    for (int i = r + 1; ; ++i) {
        siz[i] = siz[i - 1] - 1;
        if (siz[i] == r) break;
    }
    int me = 1;
    for (int i = 1; i <= r; ++i) {
        for (int j = 1; j <= siz[i]; ++j) {
            arr[i][j] = me++;
        }
    }
    for (int i = r + 1; i < r + r; ++i) {
        for (int j = 1; j <= siz[i]; ++j) {
            arr[i][j] = me++;
        }
    }


    for (int i = 1; i <= r + r - 1; ++i) {
        for (int j = 1; j <= siz[i]; ++j) {
            if (has[arr[i][j]] == 1) continue;
            if (vis[i][j]) continue;
            isOut = 0;
            cur.clear();
            dfs(i, j);
            if (isOut == 0) continue;
            for (int k = 0; k < sz(cur); ++k)
                outer[cur[k]] = 1;
        }
    }
    outer[0] = 1;
    int ans = 0;
    for (int i = 1; i <= r + r - 1; ++i) {
        for (int j = 1; j <= siz[i]; ++j) {
            me = arr[i][j];
            if (has[me] == 0) continue;
            //cout << "me  =  " << me << "  " << ans << "  =>  ";  
            if (!has[arr[i-1][j]] && outer[arr[i-1][j]]) ++ans;
            if (!has[arr[i][j-1]] && outer[arr[i][j-1]]) ++ans;
            if (!has[arr[i+1][j]] && outer[arr[i+1][j]]) ++ans;
            if (!has[arr[i][j+1]] && outer[arr[i][j+1]]) ++ans;
            if (i < r) {
                if (!has[arr[i-1][j-1]] && outer[arr[i-1][j-1]]) ++ans;
                if (!has[arr[i+1][j+1]] && outer[arr[i+1][j+1]]) ++ans;
            } else if (i == r) {
                if (!has[arr[i-1][j-1]] && outer[arr[i-1][j-1]]) ++ans;
                if (!has[arr[i+1][j-1]] && outer[arr[i+1][j-1]]) ++ans;
            } else {
                if (!has[arr[i-1][j+1]] && outer[arr[i-1][j+1]]) ++ans;
                if (!has[arr[i+1][j-1]] && outer[arr[i+1][j-1]]) ++ans;
            }
            //cout << ans << endl;
        }
    }
    cout << ans << endl;
    return 0;
}