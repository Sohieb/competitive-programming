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

int n, p;
string str;
int f[2];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    cin >> n >> p >> str;
    bool bad = 1;
    for(int i = 0; i < n; ++i){
        if(i + p >= n){
            str[i] = (str[i] == '.'?'0':str[i]);
            continue;
        }
        int j = i + p;
        if(str[i] != str[j] || str[i] == '.') bad = 0;
        if(str[i] != '.' && str[j] != '.')
            continue;
        if(str[i] == '.') str[i] = (str[j] != '0'?'0':'1');
        if(str[j] == '.') str[j] = (str[i] != '0'?'0':'1');
    }
    if(bad)
        printf("No\n");
    else
        cout << str << endl;
    return 0;
}
