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

char str[100005];
int cnt[100005];

vector<int> z_function(string s){
    int n = sz(s);
    vector<int> z(n);
    for(int i = 1, l = 0, r = 0; i < n; ++i){
        if(i <= r) z[i] = min(r - i + 1, z[i - l]);
        while(i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if(i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);
#endif
    scanf("%s", str);
    vector<int> z = z_function(str);
    z[0] = sz(z);
    for(int i = sz(z) - 1; i >= 0; --i)
        cnt[z[i]]++;
    for(int i = sz(z); i > 0; --i)
        cnt[i] += cnt[i + 1];
    vector<ii> ans;
    for(int i = 1; i <= sz(z); ++i)
        if(z[sz(z) - i] + sz(z) - i == sz(z))
            ans.push_back({i, cnt[i]});
    printf("%d\n", sz(ans));
    for(int i = 0; i < sz(ans); ++i)
        printf("%d %d\n", ans[i].F, ans[i].S);
    return 0;
}