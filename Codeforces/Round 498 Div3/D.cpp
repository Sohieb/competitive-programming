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
char s1[100005];
char s2[100005];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    scanf("%d%s%s", &n, s1, s2);
    int ans = 0;
    for(int i = 0; i < (n + 1) / 2; ++i){
        int j = n - i - 1;
        if(i == j){
            ans += s1[i] != s2[i];
            break;
        }
        if(s1[i] == s2[i] && s1[j] == s2[j]) continue;
        if(s1[i] == s2[j] && s1[j] == s2[i]) continue;
        if(s1[i] == s1[j] && s2[i] == s2[j]) continue;
        ans += 2 - (s1[i] == s2[i] || s1[i] == s2[j] || s2[i] == s2[j]
            || s1[j] == s2[i] || s1[j] == s2[j]);
    }
    cout << ans << endl;
    return 0;
}
