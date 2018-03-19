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

int n, k;
int a[400005];
map<int,int> cnt;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#endif
	sf(n), sf(k);
	for(int i = 0; i < n; ++i)
		sf(a[i]);
	ll res = 0;
	int cntK = 0,j = 0;
	cnt[a[0]]++;
	if(cnt[a[0]] == k)
		++cntK;
	for(int i = 0; i < n; ++i){
		while(cntK <= 0 && j + 1 < n){
			cnt[a[++j]]++;
			if(cnt[a[j]] == k)
				++cntK;
		}
		if(cntK > 0)
			res += n - j;
		cnt[a[i]]--;
		if(cnt[a[i]] == k -1)
			cntK--;
	}
	printf("%lld\n", res);
    return 0;
}