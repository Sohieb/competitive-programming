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

const db eps = 1e-9;
const db pi = acos(-1);
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const int mod = 1000 * 1000 * 1000 + 7;

pii a[10][10];
int d;

int main() {
    for (int i = 1; i <= 4; ++i)
        for (int j = 1; j <= 4; ++j)
            scanf("%d", &a[i][j].F);
    scanf("%d", &d);
    if (d == 0) {           // left
        for (int i = 1; i <= 4; ++i) {
            vector<int> v;
            for (int j = 1; j <= 4; ++j) {
                if (a[i][j].F) v.push_back(a[i][j].F);
                a[i][j].F = 0;
            }
            for (int j = 0; j < sz(v); ++j)
                a[i][j + 1].F = v[j];
            for (int j = 1; j <= 4; ++j)
                if (a[i][j].F == a[i][j + 1].F) {
                    a[i][j].F *= 2;
                    for (int k = j + 1; k <= 4; ++k)
                        a[i][k].F = a[i][k + 1].F;
                }
        }
    } else if (d == 1) {    // up 
        for (int j = 1; j <= 4; ++j) {
            vector<int> v;
            for (int i = 1; i <= 4; ++i) {
                if (a[i][j].F) v.push_back(a[i][j].F);
                a[i][j].F = 0;
            }
            for (int i = 0; i < sz(v); ++i)
                a[i + 1][j].F = v[i];
            for (int i = 1; i <= 4; ++i) 
                if (a[i][j].F == a[i + 1][j].F) {
                    a[i][j].F *= 2;
                    for (int k = i + 1; k <= 4; ++k)
                        a[k][j].F = a[k + 1][j].F;
                }
        }
    } else if (d == 2) {    // right
        for (int i = 1; i <= 4; ++i) {
            vector<int> v;
            for (int j = 4; j >= 1; --j) {
                if (a[i][j].F) v.push_back(a[i][j].F);
                a[i][j].F = 0;
            }
            for (int j = 0; j < sz(v); ++j)
                a[i][4 - j].F = v[j];
            for (int j = 4; j >= 1; --j)
                if (a[i][j].F == a[i][j - 1].F) {
                    a[i][j].F *= 2;
                    for (int k = j - 1; k >= 1; --k)
                        a[i][k].F = a[i][k - 1].F;
                }
        }     
    } else {                // down
        for (int j = 1; j <= 4; ++j) {
            vector<int> v;
            for (int i = 4; i >= 1; --i) {
                if (a[i][j].F) v.push_back(a[i][j].F);
                a[i][j].F = 0;
            }
            for (int i = 0; i < sz(v); ++i)
                a[4 - i][j].F = v[i];
            for (int i = 4; i >= 1; --i) 
                if (a[i][j].F == a[i - 1][j].F) {
                    a[i][j].F *= 2;
                    for (int k = i - 1; k >= 1; --k)
                        a[k][j].F = a[k - 1][j].F;
                }
        }
    }
    for (int i = 1; i <= 4; ++i)
        for (int j = 1; j <= 4; ++j)
            printf("%d%c", a[i][j].F, " \n"[j == 4]);
    return 0;
}
