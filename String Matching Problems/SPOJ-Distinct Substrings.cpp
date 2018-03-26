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

int T;
char str[1005];
int trie[500000][128], lst;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    scanf("%d", &T);
    while(T--){
        lst = 0;
        memset(trie, -1, sizeof trie);
        scanf("%s", str);
        for(int i = 0; str[i]; ++i){
            int me = 0;
            for(int j = i; str[j]; ++j){
                int &nxt = trie[me][str[j]];
                if(nxt == -1)
                    nxt = ++lst;
                me = nxt;
            }
        }
        printf("%d\n", lst);
    }
    return 0;
}