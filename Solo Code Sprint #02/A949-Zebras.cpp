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

string str;
vector<int> ans[200200];

int main() {
    cin >> str;
    if (str[0] == '1')
        return !printf("-1\n");
    int cnt0 = count(all(str), '0');
    int cnt1 = sz(str) - cnt0;
    if (cnt1 >= cnt0) return !printf("-1\n");
    vector<int> e0, e1;
    int nxt = 0;
    for (int i = 0; i < sz(str); ++i) {
        if (str[i] == '0') {
            int me;
            if (!e1.empty()) {
                me = e1.back();
                e1.pop_back();
            } else {
                me = nxt++;    
            }
            ans[me].push_back(i);
            e0.push_back(me);
        } else {
            if (e0.empty())
                return !printf("-1\n");
            int me = e0.back();
            e0.pop_back();
            ans[me].push_back(i);
            e1.push_back(me);
        }
    }
    if (sz(e1) > 0) return !printf("-1\n");
    printf("%d\n", nxt);
    for (int i = 0; i < nxt; ++i) {
        printf("%d ", sz(ans[i]));
        for (int j = 0; j < sz(ans[i]); ++j)
            printf("%d%c", ans[i][j] + 1, " \n"[j==sz(ans[i])-1]);
    }
    return 0;
}