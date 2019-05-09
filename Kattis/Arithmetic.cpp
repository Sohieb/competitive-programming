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

string s1, s2;

string get8to2(char c) {
	if (c == '0') return "000";
	if (c == '1') return "001";
	if (c == '2') return "010";
	if (c == '3') return "011";
	if (c == '4') return "100";
	if (c == '5') return "101";
	if (c == '6') return "110";
	return "111";
}

char get2to16(string s) {
	if (s == "0000") return '0';
	if (s == "0001") return '1';
	if (s == "0010") return '2';
	if (s == "0011") return '3';
	if (s == "0100") return '4';
	if (s == "0101") return '5';
	if (s == "0110") return '6';
	if (s == "0111") return '7';
	if (s == "1000") return '8';
	if (s == "1001") return '9';
	if (s == "1010") return 'A';
	if (s == "1011") return 'B';
	if (s == "1100") return 'C';
	if (s == "1101") return 'D';
	if (s == "1110") return 'E';
	return 'F';
}

int main() {
    cin >> s1;
    for (char c : s1)
    	s2 += get8to2(c);
    while (sz(s2) % 4)
    	s2 = "0" + s2;
    string res;
    for (int i = 0; i < sz(s2); i += 4)
    	res += get2to16(s2.substr(i, 4));
    while (sz(res) > 1 && res[0] == '0')
    	res.erase(0, 1);
    cout << res << endl;
    return 0;
}
