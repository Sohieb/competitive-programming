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

vector<int> z_function(string s){
  int N = sz(s);
  vector<int> z(N);
  for(int i = 1, l = 0, r = 0; i < N; ++i){
    if(i <= r) z[i] = min(r - i + 1, z[i - l]);
    while(i + z[i] < N && s[z[i]] == s[i + z[i]])
      ++z[i];
    if(i + z[i] - 1 > r)
      l = i, r = i + z[i] - 1;
  }
  return z;
}

char str[1000005];

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);
#endif
  scanf("%s", str);
  vector<int> z = z_function(str);
  int j = 0;
  int mx = 0;
  for(int i = 1; str[i]; ++i){
    if(!z[i])continue;
    if(i + z[i] == sz(z))
      if(z[i] <= mx)
        if(z[i] > z[j]) j = i;
    mx = max(z[i], mx);
  }
  if(z[j] == 0)
    return 0 * printf("Just a legend\n");
  for(int i = 0; i < z[j]; ++i)
    printf("%c", str[j + i]);
  pnl;
  return 0;
}