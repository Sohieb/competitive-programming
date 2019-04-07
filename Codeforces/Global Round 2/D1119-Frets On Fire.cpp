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

int n, q;
ll arr[100100];
pair<int, pair<ll, ll> > qu[100100];
ll ans[100100];

bool cmp(pair<int, pair<ll, ll> > a, pair<int, pair<ll, ll> > b) {
	return (a.S.S - a.S.F < b.S.S - b.S.F);
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
    	scanf("%lld", &arr[i]);
    }
    sort(arr, arr + n);
    n = unique(arr, arr + n) - arr;
    vector<ll> diff;
    for (int i = 0; i < n - 1; ++i)
    	diff.push_back(arr[i + 1] - arr[i]);
    sort(all(diff));
    // // for (auto v : diff)
    // // 	cout << v << " " ;
    // cout << endl;
    scanf("%d", &q);
    for (int i = 0; i < q; ++i) {
    	scanf("%lld%lld", &qu[i].S.F, &qu[i].S.S);
    	qu[i].F = i;
    }
    sort(qu, qu + q, cmp);
    int lst = 0;
    ll bad = 0;
    for (int i = 0; i < q; ++i) {
    	ll len = qu[i].S.S - qu[i].S.F + 1;
    	while (lst < sz(diff) && len > diff[lst])
    		bad += diff[lst++];
    	ans[qu[i].F] = len * (n - lst) + bad;
    }
    for (int i = 0; i < q; ++i)
    	printf("%lld%c", ans[i], " \n"[i==q-1]);
    return 0;
}