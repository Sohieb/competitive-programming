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

int T;
int n, a[100005];
int cnt[23][100005];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    sf(T);
    while(T--){
        sf(n);
        memset(cnt, 0, sizeof cnt);
        for(int i = 1; i <= n; ++i){
            sf(a[i]);
            for(int j = 0; j < 22; ++j)
                if(a[i] & (1 << j))
                    cnt[j][i] = 1;
        }
        ll sum = 0;
        for(int j = 0; j < 22; ++j){
            for(int i = 1; i <= n; ++i)
                cnt[j][i] += cnt[j][i - 1];
            cnt[j][n + 1] = 1000000;
            int nxt = 1;
            for(int i = 1; i <= n; ++i){
                if((a[i] & (1 << j)) == 0)
                    continue;
                nxt = max(nxt, i);
                while(cnt[j][nxt] - cnt[j][i - 1] == nxt - i + 1)
                    ++nxt;
                sum += (nxt - i) * (1LL << j);
            }
        }
        printf("%lld\n", sum);
        
    }
    return 0;
}