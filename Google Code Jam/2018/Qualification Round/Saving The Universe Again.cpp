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
int p;
string str;

int getDamage(string s){
    int res = 0, pwr = 1;
    for(int i = 0; i < sz(s); ++i){
        if(s[i] == 'S') res += pwr;
        else pwr *= 2;
    }
    return res;
}

int main() {
#ifndef ONLINE_JUDGE
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    cin >> T;
    for(int C = 1; C <= T; ++C){
        cin >> p >> str;
        if(count(all(str), 'S') > p){
            printf("Case #%d: IMPOSSIBLE\n", C);
            continue;
        }
        int out = 0;
        while(getDamage(str) > p){
            ++out;
            for(int j = sz(str) - 1; j > 0; --j){
                if(str[j] == 'S' && str[j - 1] == 'C'){
                    swap(str[j], str[j - 1]);
                    break;
                }
            }
        }
        printf("Case #%d: %d\n", C, out);
    }
    return 0;
}