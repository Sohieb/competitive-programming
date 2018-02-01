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

int T;
int n, c;
int arr[100100];

bool can(int len){
  int rem = c - 1, lst = arr[0];
  for(int i = 1; i < n; ++i){
    if(arr[i] - lst < len)
      continue;
    --rem;
    lst = arr[i];
  }
  return (rem < 1);
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);
#endif
  sf(T);
  while(T--){
    sf(n), sf(c);
    for(int i = 0; i < n; ++i)
      sf(arr[i]);
    sort(arr, arr + n);
    int l = 1, r = inf, mid;
    while(l < r){
      mid = l + (r - l + 1) / 2;
      if(can(mid)) l = mid;
      else r = mid - 1;
    }
    pf(l);
  }
  return 0;
}