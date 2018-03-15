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

string s, t;
int cnt[2][26];
int lcp1[2110][2110], lcp2[2110][2110];
int dp[2110];

int solve(int i){
    if(i == sz(t)) return 0;
    int &ret = dp[i];
    if(~ret) return ret;
    ret = inf;
    for(int j = 0; j < sz(s); ++j){
        if(lcp1[i][j]) ret = min(ret, solve(i + lcp1[i][j]) + 1);
        if(lcp2[i][j]) ret = min(ret, solve(i + lcp2[i][j]) + 1);
    }
    return ret;
}

void getPath(int i){
    if(i == sz(t)) return;
    int &ret = dp[i];
    for(int j = 0; j < sz(s); ++j){
        if(lcp1[i][j] && ret == solve(i + lcp1[i][j]) + 1){
            printf("%d %d\n", j + 1, j + lcp1[i][j]);
            getPath(i + lcp1[i][j]);
            return;
        }
        if(lcp2[i][j] && ret == solve(i + lcp2[i][j]) + 1){
            printf("%d %d\n", j + 1, j + 2 - lcp2[i][j]);
            getPath(i + lcp2[i][j]);
            return;
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);
#endif
    cin >> s >> t;
    for(int i = 0; i <sz(s); ++i)
        cnt[0][s[i] - 'a'] = 1;
    for(int i = 0; i <sz(t); ++i)
        cnt[1][t[i] - 'a'] = 1;
    for(int i = 0; i < 26; ++i)
        if(cnt[1][i] > cnt[0][i])
            return 0 * printf("-1\n");
    for(int i = sz(s) - 1; i >= 0; --i)
        for(int j = sz(t) - 1; j >= 0; --j)
            lcp1[j][i] = (lcp1[j + 1][i + 1] + (s[i] == t[j])) * (s[i] == t[j]);
    for(int i = 0; i < sz(s); ++i)
        for(int j = sz(t) - 1; j >= 0; --j){
            if(i)
                lcp2[j][i] = (lcp2[j + 1][i - 1] + (s[i] == t[j])) * (s[i] == t[j]);
            else
                lcp2[j][i] = (s[i] == t[j]);
        }
    memset(dp, -1, sizeof dp);
    printf("%d\n", solve(0));
    getPath(0);
    return 0;
}