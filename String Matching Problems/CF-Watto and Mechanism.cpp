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
char str[600006];
int trie[600006][4], lst;
int isEnd[600006];

bool solve(int me, int i, int w){
    if(w > 1) return 0;
    if(!str[i]) return w;
    bool res = 0;
    for(int j = 0; j < 3; ++j)
        if(~trie[me][j])
            res |= solve(trie[me][j], i + 1, w + (j != str[i] - 'a'));
    return res;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);
#endif
    scanf("%d%d", &n, &m);
    memset(trie, -1, sizeof trie);
    for(int i = 0; i < n; ++i){
        scanf("%s", str);
        int me = 0;
        for(int j = 0; str[j]; ++j){
            int nxt = trie[me][str[j] - 'a'];
            if(nxt == -1)
                trie[me][str[j] - 'a'] = ++lst,
                nxt = lst;
            me = nxt;
        }
        isEnd[me] = 1;
    }
    for(int i = 0; i < m; ++i){
        scanf("%s", str);
        if(solve(0, 0, 0))
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}