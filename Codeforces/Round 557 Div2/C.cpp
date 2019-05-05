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
int a[100005];
vector<int> idx[100005];

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 0; i < k; ++i)
    	scanf("%d", &a[i]), idx[a[i]].push_back(i);
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
    	// (i, i)
    	if (sz(idx[i]) == 0) ans++;
    	// (i, i - 1)
    	if (i > 1) {
    		if (sz(idx[i - 1]) == 0) ++ans;
    		else if (sz(idx[i]) == 0) ++ans;
    		else if (idx[i - 1].back() < idx[i][0]) ++ans;
    	}
    	// (i, i + 1)
    	if (i < n) {
    		if (sz(idx[i + 1]) == 0) ++ans;
    		else if (sz(idx[i]) == 0) ++ans;
    		else if (idx[i + 1].back() < idx[i][0]) ++ans;	
    	}
    }
    cout << ans << endl;
    return 0;
}