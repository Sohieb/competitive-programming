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
string str[100100];
pair<int, int> arr[100100];
char tmp[500005];
stack<char> st;
int need;
map<pii, int> mp;

int main() {
    scanf("%d", &n);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%s", tmp);
        str[i] = tmp;
        while(!st.empty()) st.pop();
        need = 0;
        for (int j = 0; tmp[j]; ++j) {
            if (tmp[j] == '(') {
                st.push(tmp[j]);
            } else {
                if (!st.empty()) st.pop();
                else ++need;
            }
        }
        arr[i].F = need;
        while(!st.empty()) st.pop();
        need = 0;
        for (int j = sz(str[i]) - 1; j >= 0; --j) {
            if (tmp[j] == ')') {
                st.push(tmp[j]);
            } else {
                if (!st.empty()) st.pop();
                else ++need;
            }
        }
        arr[i].S = need;
        if (arr[i].F > 0 && arr[i].S > 0) continue;
        if (mp[{arr[i].S, arr[i].F}] > 0) {
            ++ans;
            mp[{arr[i].S, arr[i].F}]--;
        } else
            mp[{arr[i].F, arr[i].S}]++;
    }
    cout << ans << endl;
    return 0;
}
