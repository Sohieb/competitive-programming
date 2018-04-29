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
int n, m, k;
int x, s;

pii a[100005];
int mnA[100005];
pii b[100005];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    sf(T);
    while(T--){
        scanf("%d%d%d", &n, &m, &k);
        sf(x), sf(s);
        for(int i = 0; i < m; ++i)
            sf(a[i].S);
        for(int i = 0; i < m; ++i)
            sf(a[i].F);
        for(int i = 0; i < k; ++i)
            sf(b[i].F);
        for(int i = 0; i < k; ++i)
            sf(b[i].S);
        sort(a, a + m);
        mnA[0] = a[0].S;
        for(int i = 1; i < m; ++i)
            mnA[i] = min(mnA[i - 1], a[i].S);
        long long ans = n * 1LL * x;
        for(int i = 0; i < m; ++i){
            if(a[i].F > s) break;
            ans = min(ans, n * 1LL * mnA[i]);
        }
        for(int i = 0; i < k; ++i){
            if(b[i].S > s) continue;
            int rem = s - b[i].S;
            int need = max(0, n - b[i].F);
            if(a[0].F > rem){
                ans = min(ans, need * 1LL * x);
                continue;
            }
            int l = 0, r = m - 1, mid;
            while(l < r){
                mid = l + (r - l + 1) / 2;
                if(a[mid].F <= rem) l = mid;
                else r = mid - 1;
            }
            int newX = mnA[l];
            ans = min(ans, need * 1LL * newX);
        }
        printf("%lld\n", ans);
    }

    return 0;
}