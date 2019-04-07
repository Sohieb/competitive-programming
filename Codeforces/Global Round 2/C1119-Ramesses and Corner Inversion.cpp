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
int A[505][505], B[505][505], C[505][505];;

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i)
    	for (int j = 0; j < m; ++j)
    		scanf("%d", &A[i][j]);
    for (int i = 0; i < n; ++i)
    	for (int j = 0; j < m; ++j)
    		scanf("%d", &B[i][j]);
    int Az = 0, Bz = 0;
    int diff = 0;
    queue<pii> bad;
    for (int i = 0; i < n; ++i) {
    	for (int j = 0; j < m; ++j) {
    		if (A[i][j] != B[i][j]) ++diff;
    		Az += (A[i][j] == 0);
    		Bz += (B[i][j] == 0);
    		C[i][j] = A[i][j] ^ B[i][j];
    		if (C[i][j]) bad.push({i, j});
    		// cout << C[i][j] << " " ;
    	}
    	// cout << endl;
    }
    while (!bad.empty()) {
    	int i = bad.front().F;
    	int j = bad.front().S;
    	bad.pop();
    	if (i == n - 1 || j == m - 1) continue;
    	if (C[i][j] == 0) continue;
    	C[i][j] ^= 1;
    	C[i + 1][j] ^= 1;
    	C[i][j + 1] ^= 1;
    	C[i + 1][j + 1] ^= 1;
    	if (C[i + 1][j]) bad.push({i + 1, j});
    	if (C[i][j + 1]) bad.push({i, j + 1});
    	if (C[i + 1][j + 1]) bad.push({i + 1, j + 1});
    }
    for (int i = 0; i < n; ++i)
    	for (int j = 0; j < m; ++j)
    		if (C[i][j] == 1) {
    			cout << "No\n";
    			return 0;
    		}
    cout << "Yes\n";
    // cout << diff << endl;
    // cout << Az << " " << (n * m - Az) << endl;
    // cout << Bz << " " << (n * m - Bz) << endl;
    return 0;
}