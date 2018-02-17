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
char s1[100100];
char s2[100100];

int par[30];

int findSet(int u){
  return (u == par[u]? u : par[u] = findSet(par[u]));
}

bool isSameSet(int u, int v){
  return (findSet(u) == findSet(v));
}

void unionSet(int u, int v){
  if(isSameSet(u,v))
    return;
  par[findSet(u)] = par[findSet(v)];
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);
#endif
  for(int i = 0 ; i < 30; ++i)
    par[i] = i;
  scanf("%d%s%s",&n, s1, s2);
  vector<pair<char,char> > out;
  for(int i = 0; i < n; ++i){
    if(isSameSet(s1[i] - 'a', s2[i] - 'a'))
      continue;
    out.push_back({s1[i], s2[i]});
    unionSet(s1[i] - 'a', s2[i] - 'a');
  }
  printf("%d\n",sz(out));
  for(int i = 0; i < sz(out); ++i)
    printf("%c %c\n",out[i].F, out[i].S);
  return 0;
}