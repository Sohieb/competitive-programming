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
string str;
int arr[10][10];

pair<int,int> getCor(int a){
  for(int i = 1; i < 5; ++i)
    for(int j = 1; j < 5; ++j)
      if(arr[i][j] == a)
        return {i, j};
  return {100000, 100000};
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);
#endif
  memset(arr, -1, sizeof arr);
  for(int i = 1; i < 4; ++i)
    for(int j = 1; j < 4; ++j)
      arr[i][j] = (i - 1) * 3 + j;
  arr[4][2] = 0;
  cin >> n >> str;
  vector<int> can = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  for(int i = 1; i < n; ++i){
    ii p1 = getCor(str[i - 1] - '0');
    ii p2 = getCor(str[i] - '0');
    int dx = p2.F - p1.F;
    int dy = p2.S - p1.S;
    for(int j = 0; j < sz(can); ++j){
      p1 = getCor(can[j]);
      p2 = {p1.F + dx, p1.S + dy};
      if(p2.F > 0 && p2.S > 0 && ~arr[p2.F][p2.S]){
        can[j] = arr[p2.F][p2.S];
        continue;
      }
      can.erase(can.begin() + j);
      --j;
    }
  }
  if(sz(can) > 1)
    puts("NO");
  else
    puts("YES");
  return 0;
}