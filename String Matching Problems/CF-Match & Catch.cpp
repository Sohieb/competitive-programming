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

char s1[5005], s2[5005];
int lcp[5005][5005];
int lcp1[5005][5005];
int lcp2[5005][5005];
int mn1[5005], mn2[5005];
int n1, n2;

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);
#endif
    scanf("%s%s", s1, s2);
    n1 = strlen(s1), n2 = strlen(s2);
    for(int i = n1 - 1; i >=0; --i)
        for(int j = n1 - 1; j >=0; --j)
            lcp1[i][j] = lcp1[i + 1][j + 1] * (s1[i] == s1[j]) + (s1[i] == s1[j]);
    for(int i = n2 - 1; i >=0; --i)
        for(int j = n2 - 1; j >=0; --j)
            lcp2[i][j] = lcp2[i + 1][j + 1] * (s2[i] == s2[j]) + (s2[i] == s2[j]);
    for(int i = n1 - 1; i >=0; --i)
        for(int j = n2 - 1; j >=0; --j)
            lcp[i][j] = lcp[i + 1][j + 1] * (s1[i] == s2[j]) + (s1[i] == s2[j]);
    for(int i = 0; i < n1; ++i){
        int mx = 0;
        for(int j = 0; j < n1; ++j)
            if(i != j)
                mx = max(mx, lcp1[i][j]);
        mn1[i] = mx + 1;
    }
    for(int i = 0; i < n2; ++i){
        int mx = 0;
        for(int j = 0; j < n2; ++j)
            if(i != j)
                mx = max(mx, lcp2[i][j]);
        mn2[i] = mx + 1;
    }
    int res = inf;
    for(int i = 0; i < n1; ++i)
        for(int j = 0; j < n2; ++j)
            if(lcp[i][j] >= max(mn1[i], mn2[j]))
                res = min(res, max(mn1[i], mn2[j]));
    if(res == inf)
        res = -1;
    printf("%d\n", res);
	return 0;
}