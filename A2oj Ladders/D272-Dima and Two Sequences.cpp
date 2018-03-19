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

int n, m, a, bad;
map<int, int> cnt;
map<ii, int> point;

int fac(int x){
    if(x <= 1) return 1;
    int res = fac(x - 1);
    while(bad && x % 2 == 0)
        x /= 2, --bad;
    return (x * 1LL * res) % m;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#endif
	sf(n);
    for(int i = 0; i < n; ++i){
        scanf("%d", &a);
        cnt[a]++;
        point[{a, i}]++;
    }
    for(int i = 0; i < n; ++i){
        scanf("%d", &a);
        cnt[a]++;
        point[{a, i}]++;
    }
    for(auto x : point)
        bad += x.S == 2;
    sf(m);
    int res = 1;
    for(auto c : cnt)
        res = (res * 1LL * fac(c.S)) % m;
    printf("%d\n", res);
    return 0;
}