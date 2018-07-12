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

int n, a, b;
char str[200005];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    scanf("%d%d%d%s", &n, &a, &b, str);
    int ans = 0;
    for(int i = 0; i < n; ++i){
        if(str[i] == '*') continue;
        int j = i;
        while(j < n && str[j] == '.') ++j;
        int l = j - i;
        if(a < b) swap(a, b);
        ans += min(a, (l + 1) / 2);
        a = max(0, a - (l + 1) / 2);
        ans += min(b, l / 2);
        b = max(0, b - l / 2);
        i = j;
    }
    cout << ans << endl;
    return 0;
}
