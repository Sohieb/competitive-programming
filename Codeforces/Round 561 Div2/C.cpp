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

int n;
int arr[200005];

bool cmp(int a, int b) {
	return abs(a) < abs(b);
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    	scanf("%d", &arr[i]);
    sort(arr, arr + n, cmp);
    vector<int> vp, vn;
    for (int i = 0; i < n; ++i) {
    	if (arr[i] > 0) vp.push_back(arr[i]);
    	if (arr[i] < 0) vn.push_back(abs(arr[i]));
    }
    ll ans = 0;
    for (int i = 0; i < sz(vp) - 1; ++i) {
    	if (vp[i + 1] > vp[i] + vp[i]) continue;
    	int l = i + 1, r = sz(vp) - 1, mid;
    	while (l < r) {
    		mid = l + (r - l + 1) / 2;
    		if (vp[mid] <= vp[i] + vp[i])
    			l = mid;
    		else r = mid - 1;
    	}
    	ans += l - i;
    }
    for (int i = 0; i < sz(vn) - 1; ++i) {
    	if (vn[i + 1] > vn[i] + vn[i]) continue;
    	int l = i + 1, r = sz(vn) - 1, mid;
    	while (l < r) {
    		mid = l + (r - l + 1) / 2;
    		if (vn[mid] <= vn[i] + vn[i])
    			l = mid;
    		else r = mid - 1;
    	}
    	ans += l - i;
    }
    int j = 0;
    for (int i = 0; i < sz(vn); ++i) {
    	while (j < sz(vp) && vp[j] + vp[j] < vn[i]) ++j;
    	if (j == sz(vp)) break;
    	if (vp[j] > vn[i] + vn[i]) continue;
    	int l = j, r = sz(vp) - 1, mid;
    	while (l < r) {
    		mid = l + (r - l + 1) / 2;
    		if (vn[i] + vn[i] >= vp[mid])
    			l = mid;
    		else r = mid - 1;
    	}
    	ans += (l - j + 1);
    }
    cout << ans << endl;
    return 0;
}