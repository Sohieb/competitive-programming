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
string str, v = "aeiouy";

bool isVowel(char c) {
	return (v.find(c) != string::npos);
}

int main() {
	while (scanf("%d", &n), n > 0) {
		string ans;
		int mx = -1;
		for (int i = 0; i < n; ++i) {
			cin >> str;
			int cur = 0;
			for (int j = 0; j < sz(str) - 1; ++j) {
				if (isVowel(str[j]) && str[j] == str[j + 1])
					++cur;
			}
			if (cur > mx)
				mx = cur, ans = str;
		}
		cout << ans << endl;
	}    
    return 0;
}
