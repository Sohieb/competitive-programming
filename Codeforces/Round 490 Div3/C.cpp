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

int n, k;
int cnt[26];
int bad[26];
char str[400005];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    scanf("%d%d%s", &n, &k, str);
    for(int i = 0; str[i]; ++i)
        cnt[str[i] - 'a']++;
    for(int i = 0; i < 26; ++i)
        if(cnt[i] <= k){
            bad[i] = cnt[i];
            k -= bad[i];
        } else {
            bad[i] = k;
            break;
        }
    for(int i = 0; str[i]; ++i){
        if(bad[str[i] - 'a']){
            --bad[str[i] - 'a'];
            continue;
        }
        printf("%c", str[i]);
    }
    printf("\n");
    return 0;
}
