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

int n, q;
int a, b;
int arr[100009];
int p[100009];
int f[100009];
int l, r;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    scanf("%d%d", &n, &q);
    scanf("%d%d", &f[1], &f[2]);
    scanf("%d%d", &a, &b);
    for(int i = 1; i <= n; ++i)
        scanf("%d", &arr[i]);
    for(int i = 3; i <= n + 3; ++i)
        f[i] = (a * 1LL * f[i - 2] + b * 1LL * f[i - 1]) % mod;
    while(q--){
        scanf("%d%d", &l, &r);
        if(l == r){
            arr[l] += f[1];
            if(arr[l] >= mod)
                arr[l] -= mod;
            continue;
        }
        p[l] += f[1];
        if(p[l] >= mod)
            p[l] -= mod;
        p[l + 1] = (p[l + 1] + f[2] - b * 1LL * f[1] % mod + mod) % mod;
        p[r + 1] = (p[r + 1] - f[r - l + 2] + mod) % mod;
        p[r + 2] = (p[r + 2] - a * 1LL * f[r - l + 1] % mod + mod) % mod;
    }
    for(int i = 2; i <= n; ++i)
        p[i] += (a * 1LL * p[i - 2] + b * 1LL * p[i - 1]) % mod;
    for(int i = 1; i <= n; ++i)
        printf("%lld%c", (arr[i] * 1LL + p[i]) % mod, " \n"[i ==n ]);
    return 0;
}