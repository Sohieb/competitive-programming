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

int n, x;
vector<int> v;

int MEX(){
  for(int i = 0; i < sz(v); ++i)
    if(i != v[i])
      return i;
  return (sz(v));
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);
#endif
  sf(n), sf(x);
  v.resize(n);
  for(int i = 0; i < n; ++i)
    sf(v[i]);
  sort(all(v));
  int res = 0;
  while(MEX() != x){
    ++res;
    int m = MEX();
    if(m < x)
      v.push_back(m);
    else
      break;
    sort(all(v));
  }
  pf(res);
  return 0;
}