#include <bits/stdc++.h>

using namespace std;
using namespace __gnu_cxx;

typedef double db;
typedef long long ll;
typedef pair<int,int> ii;

#define F        first
#define S        second
#define pnl      printf("\n")
#define sz(x)    (int)x.size()
#define sf(x)    scanf("%d",&x)
#define pf(x)    printf("%d\n",x)
#define all(x)   x.begin(),x.end()
#define rall(x)  x.rbegin(),x.rend()
#define FOR(a,b) for(int i = a; i < b; ++i)

const db eps = 1e-12;
const db pi = acos(-1);
const int inf = 0x3f3f3f3f;
const ll INF = inf * 2LL * inf;
const int mod = 1000 * 1000 * 1000 + 7;

ll n, m;

ll getSum(ll x, ll y){
    return (x + y) * (y - x + 1) / 2;
}

bool ok(int x){
    ll sum = getSum(x, m);
    sum = sum - (m - x + 1) + 1;
    return (sum >= n);
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);
#endif
    cin >> n >> m;
    if(n == 1)
        return 0 * printf("0\n");
    if(getSum(2, m) - m + 2 < n)
        return 0 * printf("-1\n");
    if(m >= n)
        return 0 * printf("1\n");
    ll l = 2, r = m, mid;
    while(l < r){
        mid = l + (r - l + 1) / 2;
        if(ok(mid))
            l = mid;
        else
            r = mid - 1;
    }
    printf("%lld\n", m - l + 1);
    return 0;
}