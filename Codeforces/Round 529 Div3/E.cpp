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
char str[1000006];
int lft[1000006];
int rgt[1000006];

int main() {
    scanf("%d%s", &n, str);
    stack<char> st;
    memset(lft, 0x3f, sizeof lft);
    memset(rgt, 0x3f, sizeof rgt);
    for (int i = 0; i < n; ++i) {
        if (str[i] == '(') {
            st.push(str[i]);
        } else {
            if (!st.empty())
                st.pop();
            else break;
        }
        lft[i] = sz(st);
    }
    while (!st.empty()) st.pop();
    for (int i = n - 1; i >= 0; --i) {
        if (str[i] == ')') {
            st.push(str[i]);
        } else {
            if (!st.empty())
                st.pop();
            else break;
        }
        rgt[i] = sz(st);
    }
    // for (int i = 0; i < n; ++i)
    //     cout << i << " " << lft[i] << " " << rgt[i] << endl;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (str[i] == '(') {
            int need = 0;
            if (i > 0) need += lft[i-1];
            need--;
            if (i < n - 1) need -=rgt[i + 1];
            if (need == 0) ++ans;// printf("%d\n", i);
        } else {
            int need = 0;
            if (i < n - 1) need += rgt[i + 1];
            need--;
            if (i > 0) need -= lft[i - 1];
            if (need == 0) ++ans;// printf("%d\n", i);
        }
    }
    cout << ans << endl;
    return 0;
}
