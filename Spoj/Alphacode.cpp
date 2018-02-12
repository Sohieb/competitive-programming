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

char str[5005];
int memo[5005];

int solve(int i){
  if(!str[i]) return 1;
  int &ret = memo[i];
  if(~ret) return ret;
  if(str[i] == '0')
    return ret = 0;
  ret = solve(i + 1);
  if(str[i + 1]){
    if(str[i] == '1')
      ret += solve(i + 2);
    else if(str[i] == '2' && str[i + 1] < '7')
      ret += solve(i + 2);
  }
  return ret;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);
#endif
  while(scanf("%s", str)){
    if(str[0] == '0')
      break;
    memset(memo,-1,sizeof memo);
    pf(solve(0));
  }
  return 0;
}