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
int d[3][3];

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);
#endif
  sf(n);
  memset(d, inf, sizeof d);
  sf(d[0][1]);
  d[1][0] = d[0][1];
  sf(d[0][2]);
  d[2][0] = d[0][2];
  sf(d[1][2]);
  d[2][1] = d[1][2];
  int res = 0, cur = 0;
  while(n > 1){
    int mn = inf;
    for(int i = 0; i < 3; ++i)
      mn = min(mn, d[cur][i]);
    for(int i = 0; i < 3; ++i)
      if(d[cur][i] == mn){
        res += d[cur][i];
        cur = i;
        --n;
        break;
      }
  }
  pf(res);
  return 0;
}