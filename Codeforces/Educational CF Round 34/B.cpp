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

int h1, a1, c1, h2, a2;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#endif
	cin >> h1 >> a1 >> c1 >> h2 >> a2;
    for(int i = 0; ; ++i){
        int need = i + (h2 + a1 - 1) / a1 - 1;
        if(need * a2 >= h1 + i * c1)
            continue;
        int j = (h2 + a1 - 1) / a1;
        printf("%d\n", i + j);
        for(int k = 0; k < i; ++k)
            puts("HEAL");
        for(int k = 0; k < j; ++k)
            puts("STRIKE");
        break;
    }
    return 0;
}