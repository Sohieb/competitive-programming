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

int n;
int a[101], b[101];

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);
#endif
  sf(n);
  for(int i = 0; i < n; ++i)
    sf(a[i]);
  for(int i = 0; i < n; ++i)
    sf(b[i]);
  int out = 0;
  for(int i = 1; i < 6; ++i){
    int cntA = count(a, a + n, i);
    int cntB = count(b, b + n, i);
    if((cntA + cntB) % 2)
      return puts("-1");
    out += abs(cntA - (cntA + cntB) / 2);
  }
  pf(out / 2);
  return 0;
}