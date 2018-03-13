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

int n, m, k;
string s1, s2;
int dp[1010][1010][11][2];

int solve(int i, int j, int rem, int op){
	if(rem < 0) return -inf;
	if(i == sz(s1) || j == sz(s2))
		return (-inf * (rem > 0));
	int &ret = dp[i][j][rem][op];
	if(~ret) return ret;
	if(op == 0){
		ret = max(solve(i + 1, j, rem, 0), solve(i, j + 1, rem, 0));
		if(s1[i] == s2[j])
			ret = max(ret, solve(i + 1, j + 1, rem - 1, 1) + 1);
	}else{
		ret = solve(i, j, rem, 0);
		if(s1[i] == s2[j])
			ret = max(ret, solve(i + 1, j + 1, rem, 1) + 1);
	}
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);
#endif
  	cin >> n >> m >> k;
  	cin >> s1 >> s2;
  	memset(dp, -1, sizeof dp);
  	printf("%d\n", solve(0, 0, k, 0));
	return 0;
}