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

int n, k;
int arr[5050];
int col[5050][5050];

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i)
        scanf("%d", &arr[i]);
    int cur = 0;
    vector<int> ans;
    set<int> st;
    for (int i = 0; i < n; ++i) {
        int bla = 0;
        while (col[cur][arr[i]] == 1 && bla <= k) {
            cur = (cur + 1) % k;
            ++bla;
        }
        if (bla > k) return !printf("NO\n");
        ans.push_back(cur);
        col[cur][arr[i]] = 1;
        st.insert(cur);
        cur = (cur + 1) % k;
    }
    if (sz(st) < k)
        return !printf("NO\n");
    printf("YES\n");
    for (int i = 0; i < n; ++i)
        printf("%d%c", 1 + ans[i], " \n"[i==n-1]);
}
