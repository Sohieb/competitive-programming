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

int n, A, B;
int a[100005];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    cin >> n >> A >> B;
    if(A == B)
        return !printf("%d\n", n - 1);
    for(int i = 0; i < n; ++i)
        sf(a[i]);
    sort(a + 1, a + n);
    int sum = a[0];
    for(int i = 1; i < n; ++i){
        sum += a[i];
        //cout << i << " " << sum << endl;
        if(a[0] * A / sum < B)
            return !printf("%d\n", n - i);
    }
    printf("%d\n", 0);
    return 0;
}