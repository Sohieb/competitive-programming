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

int n, a[200005];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    scanf("%d", &n);
    if(n == 1) return !printf("0\n");
    for(int i = 0; i < n; ++i)
        sf(a[i]);
    ll sum1 = a[0], sum2 = a[n - 1], res = 0;
    if(sum1 == sum2)
        res = sum1;
    int i = 0, j = n - 1;
    while(j - i > 1){
        if(sum1 < sum2)
            sum1 += a[++i];
        else
            sum2 += a[--j];
        if(sum1 == sum2)
            res = sum1;
    }
    cout << res << endl;
    return 0;
}
