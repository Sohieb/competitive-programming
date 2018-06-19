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

int a[4];
int mat[55][55];
string tmp = "ABCD";
string rev = "BADC";

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    cin >> a[0] >> a[1] >> a[2] >> a[3];
    // 0A, 1B, 2C, 3D, -1empty
    memset(mat, -1, sizeof mat);
    for(int i = 0; i < 4; ++i){
    	int x = i * 10 + 1, y = 1;
    	int k = y;
    	while(a[i] > 1){
    		mat[x++][y++] = i;
    		if(x == i * 10 + 10 - 1)
    			x = i * 10 + 1, k += 3, y = k;
    		a[i]--;
    	}
    }
    cout << 40 << " " << 50 << endl;
    for(int i = 0; i < 40; ++i){
    	for(int j = 0; j < 50; ++j){
    		if(mat[i][j] == -1)
    			mat[i][j] = rev[i / 10] - 'A';
    		printf("%c", tmp[mat[i][j]]);
    	}
    	printf("\n");
    }
    return 0;
}
