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

int n, m;
pair<int,int> a[200200], b[200200];

bool cmp(pair<int,int> p1, pair<int,int> p2){
  return p1.S < p2.S;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);
#endif
  sf(n);
  for(int i = 0; i < n; ++i)
    sf(a[i].F), sf(a[i].S);
  sf(m);
  for(int i = 0; i < m; ++i)
    sf(b[i].F), sf(b[i].S);
  int out = 0;
  sort(a, a + n);
  sort(b, b + m, cmp);
  out = max(out, a[n - 1].F - b[0].S);
  sort(a, a + n, cmp);
  sort(b, b + m);
  out = max(out, b[m - 1].F - a[0].S);
  pf(out);
  return 0;
}