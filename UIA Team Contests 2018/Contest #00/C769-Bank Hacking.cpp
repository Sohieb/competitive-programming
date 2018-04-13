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

int n;
int a[300005];
vector<int> adj[300005];
multiset<int> st;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i)
        scanf("%d", a + i), st.insert(a[i]);
    for(int i = 1; i < n; ++i){
        int u, v;
        scanf("%d%d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int res = inf;
    for(int i = 1; i <= n; ++i){
        int cur = a[i];
        st.erase(st.find(a[i]));
        for(auto v : adj[i]){
            cur = max(cur, a[v] + 1);
            st.erase(st.find(a[v]));
        }
        if(!st.empty())
            cur = max(cur, *st.rbegin() + 2);
        for(auto v : adj[i]){
            st.insert(a[v]);
        }
        st.insert(a[i]);
        res = min(res, cur);
    }
    cout << res << endl;
    return 0;
}