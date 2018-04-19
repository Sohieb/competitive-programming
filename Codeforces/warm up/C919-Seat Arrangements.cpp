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
char arr[2020][2020];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#endif
	scanf("%d%d%d", &n, &m, &k);
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            scanf(" %c", &arr[i][j]);
    int res = 0;
    for(int i = 0; i < n; ++i){
        int j = 0, cnt = 0;
        while(j < m){
            if(arr[i][j] == '.'){
                ++cnt;
                res += (cnt >= k);
            }else{
                cnt = 0;
            }
            ++j;
        }
    }
    for(int j = 0; j < m; ++j){
        int i = 0, cnt = 0;
        while(i < n){
            if(arr[i][j] == '.'){
                ++cnt;
                res += (cnt >= k);
            }else{
                cnt = 0;
            }
            ++i;
        }
    }
    if(k == 1)
        res /= 2;
    printf("%d\n", res);
    return 0;
}