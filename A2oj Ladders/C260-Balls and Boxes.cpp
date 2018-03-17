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

int n, x;
ll a[100005];
ll d[100005];

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);
#endif
    scanf("%d%d", &n, &x);
    for(int i = 0; i < n; ++i)
        scanf("%lld",&a[i]);
    ll tot = 0;
    for(int i = x - 1; i >= 0; --i){
        if(a[i] == 0){
            a[i] += tot;
            for(int j = 0; j < n; ++j)
                printf("%lld%c", a[j], " \n"[j == n - 1]);
            return 0;
        }
        --a[i], ++tot;
    }
    if(count(a, a + n, 0) > 0){
        for(int i = n - 1; i >= 0; --i)
            if(a[i] == 0){
                a[i] += tot;
                for(int j = 0; j < n; ++j)
                    printf("%lld%c", a[j], " \n"[j == n - 1]);
                return 0;
            }else{
                --a[i];
                ++tot;
            }
    }
    int j = 30;
    while(j >= 0){
        int can = 1;
        for(int i = n - 1; i >= 0; --i){
            if(a[i] >= (1 << j))
                continue;
            can = 0;
            break;
        }
        if(can == 0){
            --j;
            continue;
        }
        bool zero = 0;
        for(int i = n - 1; i >= 0; --i){
            a[i] -= (1 << j);
            tot += (1 << j);
            if(a[i] == 0) zero = 1;
        }
        if(zero) break;
    }
    for(int i = n - 1; i >= 0; --i)
        if(a[i] == 0){
            a[i] += tot;
            for(int j = 0; j < n; ++j)
                printf("%lld%c", a[j], " \n"[j == n - 1]);
            return 0;
        }else{
            --a[i];
            ++tot;
        }
    return 0;
}