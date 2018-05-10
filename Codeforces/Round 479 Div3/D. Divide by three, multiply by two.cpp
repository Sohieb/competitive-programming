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
ll a[101];
vector<int> adj[101];
int vis[101];
stack<ll> st;

void dfs(int u){
    vis[u] = 1;
    for(int i = 0; i < sz(adj[u]); ++i)
        if(vis[adj[u][i]] == 0)
            dfs(adj[u][i]);
    st.push(a[u]);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    sf(n);
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            if(a[i] * 2 == a[j] || (a[i] % 3 == 0 && a[i] / 3 == a[j]))
                adj[i].push_back(j);
    for(int i = 0; i < n; ++i)
        if(vis[i] == 0)
            dfs(i);
    while(!st.empty()){
        printf("%lld%c", st.top(), " \n"[sz(st) == 1]);
        st.pop();
    }
    return 0;
}