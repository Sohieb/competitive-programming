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

int T, A;

int main() {
#ifndef ONLINE_JUDGE
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    /*
    fflush(stdout);
    fflush(stdin);
    */
    scanf("%d", &T);
    while(T--){
        scanf("%d", &A);
        int i, j, x ,y, rem = 9;
        i = 2, j = 2;
        set<pair<int,int> > st;
        while(true){
            //--rem;
            printf("%d %d\n", i, j);
            fflush(stdout);
            scanf("%d%d", &x, &y);
            if(x == y && x == 0)
                break;
            st.insert({x, y});
            if(sz(st) == 3 * j + 3){
                //rem = 9;
                j+=3;
            }
        }
    }
    return 0;
}
