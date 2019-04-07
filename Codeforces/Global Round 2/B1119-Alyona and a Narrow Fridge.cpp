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

int n, h;
int arr[100100];

int main() {
    scanf("%d%d", &n, &h);
    for (int i = 0; i < n; ++i) {
    	scanf("%d", &arr[i]);
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
    	vector<int> tmp;
    	for (int j = 0; j <= i; ++j) {
    		tmp.push_back(arr[j]);
    	}
    	sort(rall(tmp));
    	int dummy = 0;
    	for (int j = 0; j <= i; j += 2) {
    		// cout << tmp[j] << " " ;
    		dummy += tmp[j];
    	}
    	// cout << i << " " << dummy << endl;
    	if (dummy <= h) ans = max(ans, i + 1);
    	else break;
    }
    cout << ans << endl;
    return 0;
}