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

int n, x;
int C = (1 << 18) - 1;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    cin >> n >> x;
    if(n == 2 && x == 0)
        return !printf("NO\n");
    if(n == 1)
        return !printf("YES\n%d\n", x);
    if(n == 2)
        return !printf("YES\n%d %d\n", x, 0);
    vector<int> ans;
    int cur = 0;
    for (int i = 1; i <= n - 3; ++i) {
        if(i == x){
            cur ^= n - 2;
            ans.push_back(n - 2);
            continue;
        }
        cur ^= i;
        ans.push_back(i);
    }
    if (cur == x) {
        ans.push_back(C);
        ans.push_back(C + 1);
        ans.push_back(2 * C + 1);
    } else {
        if(cur == 0) {
            ans.push_back(x ^ C);
            ans.push_back(C);
            ans.push_back(0);
        } else {
            ans.push_back(C ^ cur);
            ans.push_back(C);
            ans.push_back(x);   
        }
    }
    printf("YES\n");
    for(int i = 0; i < n; ++i)
        printf("%d%c", ans[i], " \n"[i == n-1]);
    return 0;
}
