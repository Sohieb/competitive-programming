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
string s, t;

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);
#endif
  cin >> n >> m >> s >> t;
  int res = inf;
  for(int i = 0; i < sz(t) - sz(s) + 1; ++i){
    int mis = 0;
    for(int j = 0; j < sz(s); ++j)
      mis += t[i + j] != s[j];
    res = min(res, mis);
  }
  printf("%d\n", res);
  for(int i = 0; i < sz(t) - sz(s) + 1; ++i){
    int mis = 0;
    for(int j = 0; j < sz(s); ++j)
      mis += t[i + j] != s[j];
    if(mis == res){
      for(int j = 0; j < sz(s); ++j)
        if(t[i + j] != s[j])
          printf("%d ", j + 1);
      pnl;
      return 0;
    }
  }
  return 0;
}