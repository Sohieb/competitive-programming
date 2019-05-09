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
string str[10];
int lst[26];

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i)
    	cin >> str[i];
    sort(str, str + n);
    int ans = INF;
    do {
    	memset(lst, -1, sizeof lst);
    	int cur = 0;
    	for (int i = 0; i < sz(str[0]); ++i)
    		lst[str[0][i] - 'A'] = 0;
    	for (int i = 1; i < n; ++i) {
    		for (char c : str[i]) {
    			if (lst[c - 'A'] == i - 1)
    				++cur;
    			lst[c - 'A'] = i;
    		}
    	}
    	ans = min(ans, cur);
    } while (next_permutation(str, str + n));
    cout << ans << endl;
    return 0;
}
