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

ll n, k, s;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    cin >> n >> k >> s;
    if((n - 1) * k < s || k > s)
        return !printf("NO\n");
    puts("YES");
    vector<int> ans;
    ll cur = 1, y;
    while(k){
        int mx = max(n - cur, cur - 1);
        if(s - mx >= k - 1){
            if(n - cur >= cur - 1) y = n;
            else y = 1;
            ans.push_back(y);
            cur = y;
            s -= mx;
            --k;
            continue;
        }
        int stp = s - k + 1;
        if(cur + stp <= n) y = cur + stp;
        else y = cur - stp;
        ans.push_back(y);
        cur = y;
        s -= stp;
        --k;
    }
    for(int i = 0; i < sz(ans); ++i)
        printf("%d%c", ans[i], " \n"[i == sz(ans) - 1]);
    return 0;
}
