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
const int mod = 998244353;

int n;
string str;
int cnt[200200][26];

int main() {
    cin >> n >> str;
    for (int i = 0; i < n; ++i) {
        cnt[i][str[i] - 'a'] = 1;
        if (i==0) continue;
        for (int j = 0; j < 26; ++j)
            cnt[i][j] += cnt[i-1][j];
    }
    int ans = 0;
    set<char> st;
    for (int i = 0; i < n; ++i) {
        if (sz(st) > 1) break;
        int l = i, r = n - 1, mid;
        while (l < r) {
            mid = l + (r - l) / 2;
           // cout << mid << " " << cnt[n - 1][str[n-1]-'a'] << " " << cnt[mid][str[n-1]-'a'] << endl;
            if (mid == n - 1 || cnt[n - 1][str[n-1]-'a'] - cnt[mid][str[n-1]-'a'] == n - 1 - mid)
                r = mid;
            else l = mid + 1;
        }
        //cout << i << " " << l << endl;
        if (sz(st) == 1 && str[0] != str[n-1]) {
            ans = ans + 1;
        } else {
            ans = ans + (n - l);
        }
        if (ans >= mod) ans -= mod;
        st.insert(str[i]);
    }
    cout << ans << endl;
    return 0;
}
