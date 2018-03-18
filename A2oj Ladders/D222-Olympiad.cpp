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
int a[100005];
int b[100005];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#endif
	scanf("%d%d", &n, &x);
    FOR(0, n) sf(a[i]);
    FOR(0, n) sf(b[i]);
    sort(a, a + n, greater<int>());
    sort(b, b + n);
    int mx = 0;
    int j = 0;
    for(int i = 0; i < n; ++i){
        while(j < n - 1 && a[i] + b[j] < x)
            ++j;
        if(a[i] + b[j] >= x)
            ++mx, ++j;
    }
    printf("%d %d\n", 1, mx);
    return 0;
}