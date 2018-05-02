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

const db eps = 1e-12;
const db pi = acos(-1);
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const int mod = 1000 * 1000 * 1000 + 7;

int T;
int n, q;
int arr[100005];

int getCost(long long x){
    int c = 0;
    while(x > 1){
        c += 1 + (x % 2);
        x /= 2;
    }
    return c;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    sf(T);
    while(T--){
        sf(n), sf(q);
        for(int i = 1; i <= n; ++i){
            ll a;
            scanf("%lld", &a);
            arr[i] = arr[i - 1] + getCost(a);
        }
        while(q--){
            int l, r;
            sf(l), sf(r);
            printf("%d\n", arr[r] - arr[l - 1]);
        }
    }
    return 0;
}