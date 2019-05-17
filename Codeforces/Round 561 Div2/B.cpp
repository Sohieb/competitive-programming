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
char arr[2010][2010];
string tmp = "aeiou";
string str[5] = {
	"aeiou",
	"eioua",
	"iouae",
	"ouaei",
	"uaeio"
};

int main() {
    cin >> n;
    if (n < 25)
    	return !printf("-1\n");
    int x = -1, y = -1;
    for (int i = 0; i <= n - 25; ++i) {
    	int Y = 5 + i;
    	if (5 * Y > n) break;
    	if ((n - 5 * Y) % Y == 0) {
    		x = 5 + (n - 5 * Y) / Y, y = Y;
    	}
    }	
    if (x == -1 || y == -1)
    	return !printf("-1\n");
    for (int i = 0; i < x; ++i) {
    	for (int j = 0; j < y; ++j) {
    		if (i < 5 && j < 5) {
    			arr[i][j] = str[i][j];
    			continue;
    		}
    		if (i < 5) {
    			arr[i][j] = tmp[i];
    			continue;
    		}
    		if (j < 5) {
    			arr[i][j] = tmp[j];
    			continue;
    		}
    		arr[i][j] = 'x';
    	}
    }
    string ans = "";
    for (int i = 0; i < x; ++i) {
    	for (int j = 0; j < y; ++j) {
    		ans += arr[i][j];
    		// cout << arr[i][j] << " " ;
    	}
    	// cout << endl;
    }
    cout << ans << endl;
    return 0;
}