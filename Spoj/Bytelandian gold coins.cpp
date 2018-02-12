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
map<int, ll> memo;

ll solve(int rem){
  if(!rem) return 0;
  if(memo.count(rem))
    return memo[rem];
  memo[rem] = solve(rem / 2) + solve(rem / 3) + solve(rem / 4);
  memo[rem] = max(memo[rem], rem * 1LL);
  return memo[rem];
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);
#endif
  while(sf(n) == 1){
    printf("%lld\n", solve(n));
  }
  return 0;
}