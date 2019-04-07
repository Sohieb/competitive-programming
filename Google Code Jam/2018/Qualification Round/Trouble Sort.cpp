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
int n, a[100005];

int main() {
#ifndef ONLINE_JUDGE
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    scanf("%d", &T);
    for(int C = 1; C <= T; ++C){
        scanf("%d", &n);
        vector<int> v0, v1, v2;
        for(int i = 0; i < n; ++i){
            scanf("%d", &a[i]);
            if(i % 2) v1.push_back(a[i]);
            else v0.push_back(a[i]);
        }
        sort(a, a + n);
        sort(all(v0));
        sort(all(v1));
        while(sz(v0) + sz(v1) > 0){
            if(sz(v0) > sz(v1)){
                v2.push_back(v0.back());
                v0.pop_back();
            } else {
                v2.push_back(v1.back());
                v1.pop_back();
            }
        }
        reverse(all(v2));
        int mis = -1;
        for(int i = 0; i < n; ++i)
            if(a[i] != v2[i]){
                mis = i;
                break;
            }
        if(~mis)
            printf("Case #%d: %d\n", C, mis);
        else
            printf("Case #%d: OK\n", C);
    }
    return 0;
}