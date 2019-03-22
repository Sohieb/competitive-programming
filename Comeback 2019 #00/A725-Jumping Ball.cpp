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
int can[200200];
string str;

int solve(int i) {
	if (can[i]) return can[i];
	can[i] = 1;
	if (i == 0 && str[i] == '<')
		return can[i] = -1;
	if (i == n - 1 && str[i] == '>')
		return can[i] = -1;
	int nxt;
	if (str[i] == '>') nxt = solve(i + 1);
	else nxt = solve(i - 1);
	if (nxt == -1) can[i] = -1;
	return can[i];
}

int main() {
    cin >> n >> str;
    for (int i = 0; i < n; ++i) {
    	if (can[i]) continue;
    	solve(i);
    }
    int ans = 0;
    for (int i = 0; i < n; ++i)
    	ans += (can[i] == -1);
    cout << ans << endl;
    return 0;
}
