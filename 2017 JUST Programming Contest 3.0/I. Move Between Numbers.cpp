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

int T;
int n, s, e;
string arr[255];
char str[22];
vector<int> adj[255];
int dist[255];

int getCommon(int i, int j){
    int C = 0;
    for(int k = 0; k < 10; ++k){
        int c1 = count(all(arr[i]), char('0' + k));
        int c2 = count(all(arr[j]), char('0' + k));
        C += min(c1, c2);
    }
    return C;
}

void init(){
    for(int i = 0; i < 255; ++i)
        adj[i].clear();
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    sf(T);
    while(T--){
        init();
        scanf("%d%d%d", &n, &s, &e);
        --s, --e;
        for(int i = 0; i < n; ++i)
            scanf("%s", str), arr[i] = string(str);
        for(int i = 0; i < n; ++i)
            for(int j = i + 1; j < n; ++j){
                int common = getCommon(i, j);
                if(common == 17){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                    //cout << "==> " << i << " " << j << endl;
                }
            }
        memset(dist, 0x3f, sizeof dist);
        dist[s] = 0;
        queue<pii> q;
        q.push({dist[s], s});
        while(!q.empty()){
            pii me = q.front();
            q.pop();
            if(me.F > dist[me.S])
                continue;
            for(int i = 0; i < sz(adj[me.S]); ++i){
                int v = adj[me.S][i];
                if(dist[v] <= dist[me.S] + 1)
                    continue;
                dist[v] = dist[me.S] + 1;
                q.push({dist[v], v});
            }
        }
        if(dist[e] > 255)
            puts("-1");
        else
            printf("%d\n", dist[e]);
    }
    return 0;
}