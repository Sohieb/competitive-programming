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
string str;

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);
#endif
  cin >> n >> k >> str;
  for(int i = 0; i < 100; ++i)
    for(int j = 0; j < sz(str); ++j){
      if(str[j] != 'G')
        continue;
      if(j - k >= 0 && str[j - k] != '#')
        str[j - k] = 'G';
      if(j + k < sz(str) && str[j + k] != '#')
        str[j + k] = 'G';
    }
    if(count(all(str), 'T') == 0)
      puts("YES");
    else
      puts("NO");
  return 0;
}