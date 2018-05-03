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

int n, q;
int a[1000005];
int pre[1000005];
map<int,int> lst;
pair<pii, int> qf[1000005];
int qa[1000005];
int tree[1000005];

void addXor(int x, int v){
    if(x == 0) return;
    while(x <= n){
        tree[x] ^= v;
        x += (x & -x);
    }
}

int getXor(int x){
    int res = 0;
    while(x > 0){
        res ^= tree[x];
        x -= (x & -x);
    }
    return res;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    sf(n);
    for(int i = 1; i <= n; ++i)
        sf(a[i]), pre[i] = pre[i - 1] ^ a[i];
    sf(q);
    for(int i = 0; i < q; ++i){
        scanf("%d%d", &qf[i].F.F, &qf[i].F.S);
        qf[i].S = i;
    }
    sort(qf, qf + q, [](pair<pii, int> a, pair<pii, int> b){
        return a.F.S < b.F.S;
    });
    int prev = 1;
    for(int i = 0; i < q; ++i){
        int l = qf[i].F.F, r = qf[i].F.S;
        while(prev <= r){
            addXor(lst[a[prev]], a[prev]);
            lst[a[prev]] = prev;
            addXor(lst[a[prev]], a[prev]);
            ++prev;
        }
        qa[qf[i].S] = pre[r] ^ pre[l - 1];
        qa[qf[i].S] ^= getXor(r) ^ getXor(l - 1);
    }
    for(int i = 0; i < q; ++i)
        printf("%d\n", qa[i]);
    return 0;
}
