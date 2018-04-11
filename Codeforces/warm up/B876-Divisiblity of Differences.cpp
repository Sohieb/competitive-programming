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

int n, m, k;
int a[100005];
vector<int> md[100005];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#endif
	cin >> n >> k >> m;
    for(int i = 0; i < n; ++i){
        scanf("%d", &a[i]);
        md[a[i] % m].push_back(a[i]);
    }
    for(int i = 0; i < m; ++i){
        if(sz(md[i]) < k)
            continue;
        cout << "Yes\n";
        for(int j = 0; j < k; ++j)
            printf("%d%c", md[i][j], " \n"[j == k - 1]);
        return 0;
    }
    cout << "No\n";
    return 0;
}