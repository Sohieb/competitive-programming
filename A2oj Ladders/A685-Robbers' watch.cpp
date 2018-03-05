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

int n, m;

int getSizeIn7(int x){
  int res = 0;
  while(x)
    ++res, x /= 7;
  return res;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);
#endif
  cin >> n >> m;
  int sz1 = getSizeIn7(n - 1);
  int sz2 = getSizeIn7(m - 1);
  if(sz1 + sz2 > 7)
    return 0 * printf("0\n");
  vector<int> v = {0, 1, 2, 3 , 4, 5, 6};
  if(sz1 * sz2 == 0)
    v.erase(v.begin());
  set<pair<int,int> > out;
  do{
    int num1 = 0, num2 = 0;
    for(int i = 0; i < sz1; ++i)
      num1 = num1 * 7 + v[i];
    for(int j = sz1; j < sz1 + sz2; ++j)
      num2 = num2 * 7 + v[j];
    if(num1 < n && num2 < m && num1 - num2)
      out.insert({num1, num2});
  }while(next_permutation(all(v)));
  printf("%d\n", sz(out));
  return 0;
}