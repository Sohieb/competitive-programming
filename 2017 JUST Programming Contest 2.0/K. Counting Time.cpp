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

int dx[8] = {0, 0, 1, -1, 1, -1, -1, 1};
int dy[8] = {1, -1, 0, 0, 1, -1, 1, -1};

char arr[4][4];
int vis[10];

int solve(int i, int j){
    if(j == 3) j = 0, i++;
    if(i == 3){
        int can = 1;
        for(int k = 0; k < 3; ++k)
            for(int w = 0; w < 3; ++w){
                if(arr[k][w] == '9') continue;
                int good = 0;
                for(int z = 0; z < 8; ++z){
                    int X = k + dx[z];
                    int Y = w + dy[z];
                    if(X < 0 || Y < 0 || X > 2 || Y > 2) continue;
                    if(arr[k][w] + 1 == arr[X][Y]) good = 1;
                }
                can &= good;
            }
        return can;
    }
    if(arr[i][j] != '0')
        return solve(i, j + 1);
    int res = 0;
    for(int k = 1; k < 10; ++k){
        if(vis[k] == 1) continue;
        vis[k] = 1;
        arr[i][j] = '0' + k;
        res += solve(i, j + 1);
        arr[i][j] = '0';
        vis[k] = 0;
    }
    return res;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    for(int i = 0; i < 3; ++i)
        for(int j = 0; j < 3; ++j){
            scanf(" %c", &arr[i][j]);
            vis[arr[i][j] - '0'] = 1;
        }
    printf("%d\n", solve(0, 0));
    return 0;
}