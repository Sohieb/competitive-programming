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
vector<int> v, v1, v2;

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);
#endif
  sf(n);
  v.resize(n);
  for(int i = 0; i < sz(v); ++i)
    sf(v[i]);
  v1 = v2 = v;
  sort(all(v1));
  sort(rall(v2));
  if(v1 == v2 || n < 3)
    return 0 * puts("-1");
  for(int i = 0; i < n; ++i)
    for(int j = i + 1; j < n; ++j)
      if(v[i] != v[j]){
        swap(v[i], v[j]);
        if(v !=v1 && v != v2)
          return 0 * printf("%d %d\n", i + 1, j + 1);
        swap(v[i], v[j]);
      }
  printf("-1\n");
  return 0;
}