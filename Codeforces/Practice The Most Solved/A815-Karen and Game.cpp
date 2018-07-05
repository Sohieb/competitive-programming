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

int n, m;
int a[105][105];
int sum;
string str[2] = {"row", "col"};

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    sf(n), sf(m);
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            sf(a[i][j]), sum += a[i][j];
    bool nxt = 1;
    vector<pii> ans;
    while(nxt){
        nxt = 0;
        if(n <= m){
            for(int i = 0; i < n; ++i){
                int cnt = 0;
                for(int j = 0; j < m; ++j)
                    cnt += a[i][j] > 0;
                if(cnt < m) continue;
                nxt = 1;
                sum -= m;
                ans.push_back({0, i + 1});
                for(int j = 0; j < m; ++j) --a[i][j];
                break;
            }
            if(nxt) continue;
            for(int j = 0; j < m; ++j){
                int cnt = 0;
                for(int i = 0; i < n; ++i)
                    cnt += a[i][j] > 0;
                if(cnt < n) continue;
                nxt = 1;
                sum -= n;
                ans.push_back({1, j + 1});
                for(int i = 0; i < n; ++i) --a[i][j];
                break;
            }
        } else {
            for(int j = 0; j < m; ++j){
                int cnt = 0;
                for(int i = 0; i < n; ++i)
                    cnt += a[i][j] > 0;
                if(cnt < n) continue;
                nxt = 1;
                sum -= n;
                ans.push_back({1, j + 1});
                for(int i = 0; i < n; ++i) --a[i][j];
                break;
            }
            if(nxt) continue;
            for(int i = 0; i < n; ++i){
                int cnt = 0;
                for(int j = 0; j < m; ++j)
                    cnt += a[i][j] > 0;
                if(cnt < m) continue;
                nxt = 1;
                sum -= m;
                ans.push_back({0, i + 1});
                for(int j = 0; j < m; ++j) --a[i][j];
                break;
            }
        }
    }
    if(sum > 0)
        return !printf("%d\n", -1);
    printf("%d\n", sz(ans));
    for(int i = 0; i < sz(ans); ++i)
        printf("%s %d\n", str[ans[i].F].c_str(), ans[i].S);
    return 0;
}
