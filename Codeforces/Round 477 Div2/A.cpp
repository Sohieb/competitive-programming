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

int n, s;


int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    cin >> n >> s;
    int lst = 0;
    for(int i = 0; i < n; ++i){
        int a, b;
        cin >> a >> b;
        a = a * 60 + b;
        if(i == 0){
            if(a > s)
                return !printf("%d %d\n", 0, 0);
        }
        if(lst + s + 1 < a - s)
            return !printf("%d %d\n", (lst + s + 1) / 60, (lst + s + 1) % 60);
        lst = a;
    }
    return !printf("%d %d\n", (lst + s + 1) / 60, (lst + s + 1) % 60);
}