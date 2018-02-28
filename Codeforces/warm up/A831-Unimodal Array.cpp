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
int a[105];

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);
#endif
  sf(n);
  for(int i = 0; i < n; ++i)
    sf(a[i]);
  for(int i = 0; i < n; ++i){
    bool can = 1;
    for(int j = i - 1; j >= 0; --j)
      if(a[j] < a[j + 1] || (a[j] == a[i] && a[j] == a[j + 1]))
        continue;
      else can = 0;
    for(int j = i + 1; j < n; ++j)
      if(a[j] < a[j - 1] || (a[j] == a[i] && a[j] == a[j - 1]))
        continue;
      else can = 0;
    if(can)
      return puts("YES");
  }
  puts("NO");
  return 0;
}