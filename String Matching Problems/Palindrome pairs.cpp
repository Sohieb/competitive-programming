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

string str;
int isPal[2020][2020];
int palNum[2020][2020];

int palindrome(int i, int j){
  if(i >= j)
    return 1;
  int &ret = isPal[i][j];
  if(~ret)return ret;
  ret = palindrome(i + 1, j - 1) && (str[i] == str[j]);
  return ret;
}

int solve(int i, int j){
  if(i >= j)
    return (i == j);
  int &ret = palNum[i][j];
  if(~ret)return ret;
  ret = palindrome(i, j) + solve(i + 1, j) + solve(i, j - 1) - solve(i + 1, j - 1);
  return ret;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);
#endif
  cin >> str;
  memset(isPal, -1, sizeof isPal);
  memset(palNum, -1, sizeof palNum);
  ll res = 0;
  for(int i = 0; i < sz(str); ++i)
    for(int j = i; j < sz(str); ++j){
      res += palindrome(i, j) * solve(j + 1, sz(str) - 1);
    }
  printf("%lld\n", res);
  return 0;
}