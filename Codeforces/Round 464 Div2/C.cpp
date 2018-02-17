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

int n,s,f;
int a[100100];
pair<int,int> b[100100];
ll cnt[100100];


int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);
#endif
  sf(n);
  for(int i = 0; i < n; ++i)
    sf(a[i]);
  sf(s), sf(f);
  for(int i = 0; i < n; ++i){
    b[i] = {s - i, f - i};
    while(b[i].F < 1) b[i].F += n;
    while(b[i].S < 1) b[i].S += n;
    //cout << b[i].F <<" "<<b[i].S<<endl;
    if(b[i].S >= b[i].F){
      cnt[b[i].F] += a[i];
      cnt[b[i].S] -= a[i];
    }else{
      cnt[b[i].F] += a[i];
      cnt[1] += a[i];
      cnt[b[i].S] -= a[i];
    }
  }
  for(int i = 1; i <= n; ++i)
    cnt[i] += cnt[i - 1];
  ll mx = 0;int out = 0;
  for(int i = 1; i <= n; ++i)
    if(cnt[i] > mx){
      mx = cnt[i];
      out = i;
    }
  pf(out);
  return 0;
}