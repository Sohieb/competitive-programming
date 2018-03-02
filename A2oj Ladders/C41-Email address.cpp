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

string str;

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);
#endif
  cin >> str;
  bool at = 0;
  for(int i = 1; i < sz(str); ++i){
    if(i + 2 < sz(str) - 1 && str.substr(i, 3) == "dot")
      str = str.substr(0, i) + "." + str.substr(i + 3);
    if(!at && i + 1 < sz(str) - 1 && str.substr(i, 2) == "at")
      str = str.substr(0, i) + "@" + str.substr(i + 2),
      at = 1;
  }
  cout << str << endl;
  return 0;
}