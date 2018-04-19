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

int n, a[200005];
map<int,int> cnt;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#endif
	scanf("%d%d", &n, &a[0]);
    unsigned long long resN = 0,resP = 0;
    long long sum = a[0];
    cnt[a[0]]++;
    for(int i = 1; i < n; ++i){
        scanf("%d", &a[i]);
        long long tmp = i * 1LL * a[i];
        tmp -= sum;
        tmp -= cnt[a[i] - 1];
        tmp += cnt[a[i] + 1];
        if(tmp < 0)
            resN += -tmp;
        else
            resP += tmp;
        cnt[a[i]]++;
        sum += a[i];
    }
    if(resN > resP)
        cout << "-" << resN - resP << endl;
    else
        cout << resP - resN << endl;
    return 0;
}