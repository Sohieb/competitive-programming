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

int n;
int a[100005];

int main() {
#ifndef ONLINE_JUDGE
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    scanf("%d", &n);
    priority_queue<int> pq;
    for (int i = 0; i < n; ++i)
        scanf("%d", &a[i]), pq.push(a[i]);
    int L = pq.top();
    int R = pq.top();
    pq.pop();
    int ans = 0;
    while(!pq.empty()){
        int nxt = pq.top();
        pq.pop();
        if(sz(pq) % 2){
            ans = max(ans, L - nxt);
            L = nxt;
        } else {
            ans = max(ans, R - nxt);
            R = nxt;
        }
    }
    ans = max(ans, abs(R - L));
    printf("%d\n", ans);
	return 0;
}
