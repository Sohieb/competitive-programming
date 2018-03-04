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

int n;
int a[1005];
char c[2005][2005];

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);
#endif
  for(int i = 0; i < 2003; ++i)
    for(int j = 0; j < 2003; ++j)
      c[i][j] = ' ';
  sf(n);
  int summ = 0;
  for(int i = 0; i < n; ++i)
    sf(a[i]), summ += a[i];
  int cur = 0, mn = inf, mx = -inf;
  for(int i = 0; i < n; ++i){
    cur += a[i] * (i % 2 ? -1 : 1);
    mn = min(mn, cur);
    mx = max(mx, cur);
  }
  int peak = mx + (mn < 0 ? -mn : 0);
  int sum = 0;
  cur = 0;
  for(int i = 0; i < n; ++i){
    sum += a[i];
    cur += a[i] * (i % 2 ? -1 : 1);
    if(cur != mx)
      continue;
    int y = 0;
    int tmp = sum;
    for(int j = i + 1; j < n; ++j){
      if(j % 2 == 0){ 
        while(a[j]--)
          c[--y][sum++] = '/';
      }else{
        while(a[j]--)
          c[y++][sum++] = '\\';
      }
    }
    y = 0;
    sum = tmp - 1;
    for(int j = i; j >= 0; --j){
      if(j % 2 == 0){
        while(a[j]--)
          c[y++][sum--] = '/';
      }else{
        while(a[j]--)
          c[--y][sum--] = '\\';
      }
    }
    break;
  }
  sum = summ;
  for(int i = 0; i < peak; ++i){
    for(int j = 0; j < sum; ++j)
      cout << c[i][j];
    cout << endl;
  }
  return 0;
}