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
char str[10005], tmp[1005];
string arr[100005];

int base[2], MOD[2];
map<ii, int> mp;

int dp[10005];

int solve(int i){
    if(i == n) return 1;
    int &ret = dp[i];
    if(~ret) return ret;
    ret = 0;
    ii hash;
    for(int j = 0; j < min(1000, n - i); ++j){
        hash.F = (hash.F * 1LL * base[0] + tolower(str[j + i])) % MOD[0],
        hash.S = (hash.S * 1LL * base[1] + tolower(str[j + i])) % MOD[1];
        if(mp.count(hash))
            ret |= solve(i + j + 1);
    }
    return ret;
}

void getword(int i){
    if(i == n) return;
    int &ret = dp[i];
    ii hash;
    for(int j = 0; j < min(1000, n - i); ++j){
        hash.F = (hash.F * 1LL * base[0] + tolower(str[j + i])) % MOD[0],
        hash.S = (hash.S * 1LL * base[1] + tolower(str[j + i])) % MOD[1];
        if(mp.count(hash) && solve(i + j + 1)){
            if(i) printf(" ");
            cout << arr[mp[hash]];
            getword(i + j + 1);
            return;
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);
#endif
    scanf("%d%s%d", &n, str, &m);
    base[0] = 133, base[1] = 151;
    MOD[0] = 1000000009, MOD[1] = 1000003111;
    for(int i = 0; i < m; ++i){
        scanf("%s", tmp);
        arr[i] = tmp;
        ii hash;
        for(int j = sz(arr[i]) - 1; j >= 0; --j)
            hash.F = (hash.F * 1LL * base[0] + tolower(tmp[j])) % MOD[0],
            hash.S = (hash.S * 1LL * base[1] + tolower(tmp[j])) % MOD[1];
        mp[hash] = i;
    }
    memset(dp, -1, sizeof dp);
    solve(0);
    getword(0);
    return 0;
}