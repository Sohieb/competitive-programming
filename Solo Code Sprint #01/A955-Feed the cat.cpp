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

int hh, mm;
int H, D, C, N;

int main() {
    cin >> hh >> mm >> H >> D >> C >> N;
    int needMin = 0;
    while (hh * 60 + mm < 20 * 60) {
        ++needMin;
        ++mm;
        if (mm == 60) mm = 0, ++hh;
    }
    double ans1 = (H + N - 1) / N * C;
    double ans2 = (needMin * D + H + N - 1) / N * (C * 0.8);
    printf("%.4f\n", min(ans1, ans2));
    return 0;
}
