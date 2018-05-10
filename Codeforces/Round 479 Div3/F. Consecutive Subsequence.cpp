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

int n, a[200005];
map<int, int> mp;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    sf(n);
    int res = 0;
    for(int i = 0; i < n; ++i){
        sf(a[i]);
        mp[a[i]] = max(mp[a[i]], mp[a[i] - 1] + 1);
        res = max(res, mp[a[i]]);
    }
    printf("%d\n", res);
    stack<int> seq;
    for(int i = n - 1; i >= 0; --i)
        if(mp[a[i]] == res){
            seq.push(i);
            res--;
            while(res--){
                while(1){
                    if(a[i] == a[seq.top()] - 1){
                        seq.push(i);
                        break;
                    }
                    --i;
                }
            }
            break;
        }
    while(!seq.empty()){
        printf("%d%c", seq.top() + 1, " \n"[sz(seq) == 1]);
        seq.pop();
    }
    return 0;
}