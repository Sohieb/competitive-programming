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

int T;
string str;
int dp[105][10];	// [idx][reminder]

int solve(int idx, int rem) {
	if (idx == sz(str))
		return (rem == 0);
	int &ret = dp[idx][rem];
	if (~ret) return ret;
	ret = 0;
	for (int i = 0; i < 10; ++i)
		for (int j = 0; j < 10; ++j) {
			if (i == 4 || j == 4) continue;
			int d = (i + j + rem) % 10;
			int r = (i + j + rem) / 10;
			if (d != str[idx] - '0') continue;
			ret |= solve(idx + 1, r);
		}
	return ret;
}

string A, B;

void getAns(int idx, int rem) {
	if (idx == sz(str)) return;
	for (int i = 0; i < 10; ++i)
		for (int j = 0; j < 10; ++j) {
			if (i == 4 || j == 4) continue;
			int d = (i + j + rem) % 10;
			int r = (i + j + rem) / 10;
			if (d != str[idx] - '0') continue;
			if (solve(idx + 1, r)) {
				A += char('0' + i);
				B += char('0' + j);
				getAns(idx + 1, r);
				return;
			}
		}
}

int main() {
    cin >> T;
    for (int C = 1; C <= T; ++C) {
    	cin >> str;
    	reverse(all(str));
    	memset(dp, -1, sizeof dp);
    	solve(0, 0);
    	A = B = "";
    	getAns(0, 0);
    	reverse(all(A));
    	reverse(all(B));
    	while (sz(A) > 1 && A[0] == '0') A = A.substr(1);
    	while (sz(B) > 1 && B[0] == '0') B = B.substr(1);
    	cout << "Case #" << C << ": " << A << " " << B << endl;
    }
    return 0;
}
