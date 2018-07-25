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

const db eps = 1e-9;
const db pi = acos(-1);
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const int mod = 1000 * 1000 * 1000 + 7;

int n, a[5050], b[5050];
int frq[5050], ans[5050];

int fix(int x){
    for(int i = 10000; i > 0; --i){
        if(x % (i * i) == 0){
            x /= (i * i);
            break;
        }
    }
    return x;
}

map<int, int> mp;
int comp(int x){
    if(x == 0) return 0;
    if(mp.count(x))
        return mp[x];
    else
        return mp[x] = sz(mp);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    scanf("%d", &n);
    for(int i = 0; i < n; ++i){
        scanf("%d", a + i);
        a[i] = fix(a[i]);
        b[i] = comp(a[i]);
        //cout << a[i] << " " << b[i] << endl;
    }
    for(int i = 0; i < n; ++i){
        memset(frq, 0, sizeof frq);
        int cnt = 0;
        for(int j = i; j < n; ++j){
            if(b[j] != 0){
                ++frq[b[j]];
                cnt += (frq[b[j]] == 1);
            }
            ans[max(1, cnt)]++;
            //cout << i << " " << j << " " << cnt << endl;
        }
    }
    for(int i = 1; i <= n; ++i)
        printf("%d%c", ans[i], " \n"[i==n]);
    return 0;
}
