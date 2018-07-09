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
string s1 = "abcde";
string s2 = "fghij";
string ans[4];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    cin >> n;
    int j = 0;
    for (int i = 0; i < n / 2; ++i) {
        ans[0] += s1[j % 5];
        ans[0] += s1[j++ % 5];
        ans[1] += s1[j % 5];
        ans[1] += s1[j++ % 5];
    }
    if (n % 2)
        ans[0] += s1[j % 5], ans[1] += s1[j % 5];
    cout << ans[0] << endl << ans[1] << endl;
    j = 0;
    ans[2] += s2[j % 5], ans[3] += s2[j % 5];
    --n, ++j;
    for (int i = 0; i < n / 2; ++i) {
        ans[2] += s2[j % 5];
        ans[2] += s2[j++ % 5];
        ans[3] += s2[j % 5];
        ans[3] += s2[j++ % 5];
    }
    if (n % 2)
        ans[2] += s2[j % 5], ans[3] += s2[j % 5];
    cout << ans[2] << endl << ans[3] << endl;
    return 0;
}

