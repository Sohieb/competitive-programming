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

int n, m;
pair<ll, int> arr[100005];

bool cmp(pair<ll, int> a, pair<ll, int> b){
    return a.F - a.S > b.F - b.S;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    scanf("%d%d", &n, &m);
    ll sumB = 0;
    for(int i = 0 ; i < n; ++i)
        scanf("%lld%d", &arr[i].F, &arr[i].S), sumB += arr[i].S;
    if(sumB > m)
        return !printf("%d\n", -1);
    sort(arr, arr + n, cmp);
    for(int i = n - 1; i >= 0; --i)
        arr[i].F += arr[i + 1].F;
    sumB = 0;
    for(int i = 0; i < n; ++i){
        if(sumB + arr[i].F <= m)
            return !printf("%d\n", i);
        sumB += arr[i].S;
    }
    printf("%d\n", n);
    return 0;
}
