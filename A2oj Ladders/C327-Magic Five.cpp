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

string s;
int k;

int pwr(ll base, ll pw){
    int res = 1;
    while(pw){
        if(pw % 2) res = res * 1LL * base % mod;
        base = base * 1LL * base % mod;
        pw /= 2;
    }
    return res;
}

int inv(int x){
    return pwr(x, mod - 2);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    cin >> s >> k;
    int S = (pwr(2, k * 1LL * sz(s)) - 1) * 1LL
         * inv(pwr(2, sz(s)) - 1) % mod;
    int res = 0;
    for(int i = 0; i < sz(s); ++i){
        if(s[i] != '0' && s[i] != '5')
            continue;
        res = (res + pwr(2, i) * 1LL * S) % mod; 
    }
    cout << res << endl;
    return 0;
}