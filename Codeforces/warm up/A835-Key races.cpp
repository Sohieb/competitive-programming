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

int s, v1, v2, t1, t2;

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);
#endif
  cin >> s >> v1 >> v2 >> t1 >> t2;
  if(s * v1 + t1 + t1 < s * v2 + t2 + t2)
    return puts("First");
  if(s * v1 + t1 + t1 > s * v2 + t2 + t2)
    return puts("Second");
  if(s * v1 + t1 + t1 == s * v2 + t2 + t2)
    return puts("Friendship");

  return 0;
}