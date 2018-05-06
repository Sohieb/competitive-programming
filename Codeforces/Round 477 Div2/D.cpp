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

int n, X, Y;
pii a[300005];
ll b[300005];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    cin >> n >> X >> Y;
    for(int i = 0; i < n; ++i){
        sf(a[i].F);
        a[i].S = i + 1;
    }
    sort(a, a + n);
    b[n - 1] = a[n - 1].F;
    for(int i = n - 2; i >= 0; --i){
        b[i] = max(b[i + 1], (n - i) * 1LL * a[i].F);
    }
    for(int i = 0; i < n; ++i){
        // X first
        if((n - i) * 1LL * a[i].F >= X){
            int l = i, r = n - 1, mid;
            while(l < r){
                mid = l + (r - l) / 2;
                if((mid - i + 1) * 1LL * a[i].F >= X)
                    r = mid;
                else l = mid + 1;
            }
            if(b[l + 1] >= Y){
                puts("Yes");
                for(int j = n - 1; j > l; --j){
                    if(b[j] < Y) continue;
                    printf("%d %d\n", l - i + 1, n - j);
                    for(int k = i; k <= l; ++k)
                        printf("%d%c", a[k].S, " \n"[k == l]);
                    for(int k = n - 1; k >= j; --k)
                        printf("%d%c", a[k].S, " \n"[k == j]);
                    return 0;
                }
            }
        }
    }
    swap(X, Y);
    for(int i = 0; i < n; ++i){
        // Y first
        if((n - i) * 1LL * a[i].F >= X){
            int l = i, r = n - 1, mid;
            while(l < r){
                mid = l + (r - l) / 2;
                if((mid - i + 1) * 1LL * a[i].F >= X)
                    r = mid;
                else l = mid + 1;
            }
            if(b[l + 1] >= Y){
                puts("Yes");
                for(int j = n - 1; j > l; --j){
                    if(b[j] < Y) continue;
                    printf("%d %d\n", n - j, l - i + 1);
                    for(int k = n - 1; k >= j; --k)
                        printf("%d%c", a[k].S, " \n"[k == j]);
                    for(int k = i; k <= l; ++k)
                        printf("%d%c", a[k].S, " \n"[k == l]);
                    return 0;
                }
            }
        }
    }
    puts("No");
    return 0;
}