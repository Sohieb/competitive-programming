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

char s1[27], s2[27], c;

char convert(char x){
  if(isdigit(x))
    return x;
  for(int i = 0; s1[i]; ++i)
    if(tolower(x) == s1[i]){
      if(isupper(x))
        return toupper(s2[i]);
      return s2[i];
    }
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);
#endif
  scanf("%s%s", s1, s2);
  while(scanf(" %c", &c) == 1){
    putchar(convert(c));
  }
  return 0;
}