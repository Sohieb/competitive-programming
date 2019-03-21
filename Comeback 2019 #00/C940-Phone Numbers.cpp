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

int n, k;
string str;
int arr[26];
set<char> st;

bool nxt(char &c) {
    for (int i = c - 'a' + 1; i < 26; ++i)
        if (arr[i]) {
            c = ('a' + i);
            return 1;
        }
    for (int i = 0; i < 26; ++i)
        if (arr[i]) {
            c = ('a' + i);
            return 0;
        }
}

int main() {
    cin >> n >> k;
    cin >> str;
    for (char c : str) {
        arr[c - 'a'] = 1;
        st.insert(c);
    }
    if (k > n) {
        while (sz(str) < k) str += *st.begin();
        cout << str << endl;
        return 0;
    }
    string tmp = str.substr(0, k);
    int cur = k - 1;
    while (!nxt(tmp[cur--]));
    cout << tmp << endl;
    return 0;
}
