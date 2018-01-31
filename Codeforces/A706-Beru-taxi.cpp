#include <bits/stdc++.h>

using namespace std;
using namespace __gnu_cxx;

typedef double db;
typedef long long ll;

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

int a, b, n;
int x, y, v;

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);
#endif
  sf(a), sf(b), sf(n);
  db out = inf;
  for(int i = 0; i < n; ++i){
    sf(x), sf(y), sf(v);
    db d = sqrt((a - x) * (a - x) + (b - y) * (b - y));
    out = min(out, d / v);
  }
  printf("%.9f\n", out);
  return 0;
}