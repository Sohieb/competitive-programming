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
pair<int, int> arr[200005];
map<pii, bool> seg;

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) {
    	scanf("%d%d", &arr[i].F, &arr[i].S);
    	if (arr[i].F > arr[i].S)
    		swap(arr[i].F, arr[i].S);
    	seg[arr[i]] = 1;
    }
    for (int k = 1; k < n; ++k) {
    	if (n % k) continue;
    	bool can = 1;
    	for (int i = 0; i < m; ++i) {
    		int a = arr[i].F + k;
    		int b = arr[i].S + k;
    		if (a > n) a -= n;
    		if (b > n) b -= n;
    		if (a > b) swap(a, b);
    		if (seg.count({a, b}) == 0)
    			can = 0;
    	}
    	if (can == 1) {
    		cout << "Yes\n";
    		return 0;
    	}
    }
    cout << "No\n";
    return 0;
}