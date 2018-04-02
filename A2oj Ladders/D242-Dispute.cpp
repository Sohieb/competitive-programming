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

int n, m;
vector<int> adj[100005];
int a[100005];
int b[100005];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#endif
	scanf("%d%d", &n, &m);
    for(int i = 0; i < m; ++i){
        int u, v;
        scanf("%d%d", &u, &v);
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    set<int> bad;
    for(int i = 0; i < n; ++i){
        scanf("%d", &a[i]);
        if(a[i] == 0)
            bad.insert(i);
    }
    vector<int> ans;
    while(!bad.empty()){
        int u = *bad.begin();
        bad.erase(bad.find(u));
        ++b[u];
        for(auto v : adj[u]){
            if(b[v] == a[v])
                bad.erase(bad.find(v));
            ++b[v];
            if(b[v] == a[v])
                bad.insert(v);
        }
        ans.push_back(u);
    }
    cout << sz(ans) << endl;
    for(int i = 0; i < sz(ans); ++i)
        printf("%d%c", ans[i] + 1, " \n"[i == sz(ans) - 1]);
    return 0;
}