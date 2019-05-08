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
int pal[1010][1010];

int isPal(int i, int j) {
	if (i == j) return 1;
	if (j - i == 1) return (str[i] == str[j]);
	int &ret = pal[i][j];
	if (~ret) return ret;
	if (str[i] == str[j])
		ret = isPal(i + 1, j - 1);
	else ret = 0;
	return ret;
}

int main() {
    while (cin >> str) {
    	memset(pal, -1, sizeof pal);
    	set<string> ans;
    	for (int i = 0; i < sz(str); ++i) {
    		string tmp = "";
    		for (int j = i; j < sz(str); ++j) {
    			tmp += str[j];
    			if (i != j && isPal(i, j))
    				ans.insert(tmp);
    		}
    	}
    	for (auto s : ans)
    		printf("%s\n", s.c_str());
    	printf("\n");
    }
    return 0;
}
