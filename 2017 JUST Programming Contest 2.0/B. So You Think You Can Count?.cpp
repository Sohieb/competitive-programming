#include <bits/stdc++.h>

using namespace std;
using namespace __gnu_cxx;

typedef double db;
typedef long long ll;
typedef pair<db, db> pdd;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef unsigned long long ull;

#define F          first
#define S          second
#define pnl        printf("\n")
#define sz(x)      (int)x.size()
#define sf(x)      scanf("%d",&x)
#define pf(x)      printf("%d\n",x)
#define all(x)     x.begin(),x.end()
#define rall(x)    x.rbegin(),x.rend()
#define rep(i, n)  for(int i = 0; i < n; ++i)

const db eps = 1e-12;
const db pi = acos(-1);
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const int mod = 1000 * 1000 * 1000 + 7;

int n;
string str;
int dp[10005];

int solve(int i){
    if(i == n) return 1;
    int &ret = dp[i];
    if(~ret) return ret;
    ret = 0;
    set<char> st;
    for(int j = i; j < i + 10; ++j){
        if(j == n) break;
        if(st.find(str[j]) != st.end())
            break;
        st.insert(str[j]);
        ret += solve(j + 1);
        if(ret >= mod) ret -= mod;
    }
    return ret;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    cin >> n >> str;
    memset(dp, -1, sizeof dp);
    cout << solve(0) << endl;
    return 0;
}