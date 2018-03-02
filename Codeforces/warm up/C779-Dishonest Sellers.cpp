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

int n, k;
int a[200005], b[200005];
vector<pair<int,int > > v;

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);
#endif
  sf(n), sf(k);
  for(int i = 0; i < n; ++i)
    sf(a[i]);
  for(int i = 0; i < n; ++i)
    sf(b[i]);
  int res = 0;
  for(int i = 0; i < n; ++i){
    if(a[i] <= b[i])
      res += a[i], --k;
    else
      v.push_back({a[i] - b[i], b[i]});
  }
  sort(all(v));
  for(int i = 0; i < sz(v); ++i)
    if(k > 0)
      res += (v[i].F + v[i].S), --k;
    else
      res += v[i].S;
  pf(res);
  return 0;
}