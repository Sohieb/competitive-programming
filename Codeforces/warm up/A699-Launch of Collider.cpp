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

int n, arr[200200];
char str[200200];

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);
#endif
  scanf("%d%s",&n, str);
  int out = inf;
  sf(arr[0]);
  for(int i = 1; i < n; ++i){
    sf(arr[i]);
    if(str[i] == 'L' && str[i - 1] == 'R')
      out = min(out, arr[i] - arr[i - 1]);
  }
  if(out == inf)
    pf(-1);
  else 
    pf(out / 2);
  return 0;
}