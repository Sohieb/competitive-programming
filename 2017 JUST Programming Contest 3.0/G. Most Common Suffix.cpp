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
int n, q;
char tmp[100005];
string in[10005];

vector<pii> hVal[100005];
int res[100005];

int base[2] = {133, 151};
int MOD[2] = {1000000009, 1000003111};

void init(){
    for(int i = 0; i < 100005; ++i)
        hVal[i].clear();
}

inline int add(ll v, int i){
    return ((v >= MOD[i]) ? v % MOD[i] : v);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    sf(T);
    while(T--){
        init();
        sf(n), sf(q);
        for(int i = 0; i < n; ++i){
            scanf("%s", tmp);
            in[i] = string(tmp);
            reverse(all(in[i]));
            pii hash;
            for(int j = 0; j < sz(in[i]); ++j){
                hash.F = add(hash.F * 1LL * base[0] + in[i][j], 0);
                hash.S = add(hash.S * 1LL * base[1] + in[i][j], 1);
                hVal[j + 1].push_back(hash);
            }
        }
        for(int i = 1; i < 100005; ++i){
            if(hVal[i].empty()) continue;
            sort(all(hVal[i]));
            int mx = 1, cur = 1;
            for(int j = 1; j < sz(hVal[i]); ++j){
                if(hVal[i][j] == hVal[i][j - 1])
                    ++cur;
                else{
                    mx = max(mx, cur);
                    cur = 1;
                }
            }
            mx = max(mx, cur);
            res[i] = mx;
        }
        while(q--){
            int x;
            sf(x);
            printf("%d\n", res[x]);
        }
    }
    return 0;
}