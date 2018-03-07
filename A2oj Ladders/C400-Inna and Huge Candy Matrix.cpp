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

int n, m, x, y, z, p;
int N, M;

pair<int,int> do90CW(pair<int,int> me, int rem){
  //int N = n, M = m;
  while(rem--){
    int _i = me.S;
    int _j = N - me.F - 1;
    me = {_i, _j};
    swap(N, M);
  }
  return me;
}

pair<int,int> do90CCW(pair<int,int> me, int rem){
  //int N = n, M = m;
  while(rem--){
    int _i = M - me.S - 1;
    int _j = me.F;
    me = {_i, _j};
    swap(N, M);
  }
  return me;
}

pair<int,int> HorizontalRotate(pair<int,int> me){
  me.S = M - me.S - 1;
  return me;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);
#endif
  sf(n), sf(m), sf(x), sf(y), sf(z), sf(p);
  x %= 4;
  y %= 2;
  z %= 4;
  for(int i = 0; i < p; ++i){
    pair<int, int> cell;
    sf(cell.F), sf(cell.S);
    --cell.F, --cell.S;
    N = n, M = m;
    cell = do90CW(cell, x);
    if(y) cell = HorizontalRotate(cell);
    cell = do90CCW(cell, z);
    printf("%d %d\n", cell.F + 1, cell.S + 1);
  }
  return 0;
}