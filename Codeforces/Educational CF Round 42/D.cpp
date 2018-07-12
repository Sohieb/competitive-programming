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
long long a[150005];
int del[150005];
map<ll, int> lst;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i){
        scanf("%lld", a + i);
        while(lst[a[i]]){
            del[lst[a[i]]] = 1;
            lst[a[i]] = 0;
            a[i] += a[i];
        }
        lst[a[i]] = i;
    }
    vector<ll> res;
    for(int i = 1; i <= n; ++i)
        if(!del[i]) res.push_back(a[i]);
    printf("%d\n", sz(res));
    for(int i = 0; i < sz(res); ++i)
        printf("%lld%c", res[i], " \n"[i == sz(res) - 1]);
    return 0;
}
