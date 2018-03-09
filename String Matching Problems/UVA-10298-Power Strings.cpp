#include <bits/stdc++.h>

using namespace std;
using namespace __gnu_cxx;

typedef double db;
typedef long long ll;
typedef pair<int,int> ii;

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

vector<int> z_function(string s){
  int n = sz(s);
  vector<int> z(n);
  for(int i = 1, l = 0, r = 0; i < n; ++i){
    if(i <= r) z[i] = min(r - i + 1, z[i - l]);
    while(i + z[i] < n && s[z[i]] == s[i + z[i]])
      ++z[i];
    if(i + z[i] - 1 > r)
      l = i, r = i + z[i] - 1;
  }
  return z;
}

char str[1000005];

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);
#endif
  while(scanf("%s", str)){
    if(str[0] == '.' && strlen(str) == 1)
      break;
    vector<int> z = z_function(str);
    int res = sz(z);
    for(int i = 1; i < sz(z); ++i)
      if(sz(z) % i == 0 && i + z[i] == sz(z))
        res = min(res, i);
    printf("%d\n", sz(z) / res);
  }
  return 0;
}