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
int a[500500];
ll sum[500500];

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);
#endif
  sf(n);
  int lst = 0;
  while(n--){
    int q, x;
    sf(q);
    if(q == 1){
      sf(x);
      a[lst] = x;
      if(lst)sum[lst] = sum[lst - 1] + a[lst];
      else sum[lst] = a[lst];
      lst++;
    }else{
      double res = 0;
      if(lst == 1){
        printf("%.12f\n", res);
        continue;
      }
      int l = 0, r = lst - 2;
      while(r - l > 100){
        int md1 = l + (r - l) / 3;
        int md2 = md1 + (r - l) / 3;
        if((sum[md1] + a[lst - 1]) / (md1 + 2.0) > 
            (sum[md2] + a[lst - 1]) / (md2 + 2.0))
          l = md1;
        else r = md2;
      }
      res = 1000000000000000LL;
      for(int i = l; i <= r; ++i){
        res = min(res,(sum[i] + a[lst - 1]) / (i + 2.0));
      }
      printf("%.12f\n", a[lst-1] - res);
    }
  }

  return 0;
}