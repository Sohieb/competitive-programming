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

int n;
char s1[100005];
char s2[100005];
int pwr[2][100005];
int base[2], MOD[2];
set<ii> hashSet;

void init(){
    base[0] = 133, base[1] = 151;
    MOD[0] = 1000000009, MOD[1] = 1000003111;
    pwr[0][0] = pwr[1][0] = 1;
    for(int i = 1; i <= n; ++i)
        pwr[0][i] = pwr[0][i - 1] * 133LL % MOD[0],
        pwr[1][i] = pwr[1][i - 1] * 151LL % MOD[1];
}

void printAns(int i, int len){
    for(int j = i; j < i + len; ++j)
        printf("%c", s2[j]);
    printf("\n");
}

bool ok(int len, bool done){
    if(len == 0) return true;
    hashSet.clear();
    ii me;
    for(int i = 0; i < len; ++i)
        me.F = (me.F * 1LL * base[0] + s1[i]) % MOD[0],
        me.S = (me.S * 1LL * base[1] + s1[i]) % MOD[1];
    hashSet.insert(me);
    for(int i = len; i < n; ++i){
        me.F -= s1[i - len] * 1LL * pwr[0][len - 1] % MOD[0];
        if(me.F < 0) me.F += MOD[0];
        me.S -= s1[i - len] * 1LL * pwr[1][len - 1] % MOD[1];
        if(me.S < 0) me.S += MOD[1];
        me.F = (me.F * 1LL * base[0] + s1[i]) % MOD[0],
        me.S = (me.S * 1LL * base[1] + s1[i]) % MOD[1];
        hashSet.insert(me);
    }
    me = {0, 0};
    for(int i = 0; i < len; ++i)
        me.F = (me.F * 1LL * base[0] + s2[i]) % MOD[0],
        me.S = (me.S * 1LL * base[1] + s2[i]) % MOD[1];
    if(hashSet.find(me) != hashSet.end()){
        if(done) printAns(0, len);
        return true;
    }
    for(int i = len; i < n; ++i){
        me.F -= s2[i - len] * 1LL * pwr[0][len - 1] % MOD[0];
        if(me.F < 0) me.F += MOD[0];
        me.S -= s2[i - len] * 1LL * pwr[1][len - 1] % MOD[1];
        if(me.S < 0) me.S += MOD[1];
        me.F = (me.F * 1LL * base[0] + s2[i]) % MOD[0],
        me.S = (me.S * 1LL * base[1] + s2[i]) % MOD[1];
        if(hashSet.find(me) != hashSet.end()){
            if(done) printAns(i - len + 1, len);
            return true;
        }
    }
    return false;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    scanf("%d%s%s", &n, s1, s2);
    init();
    int l = 0, r = n, mid;
    while(l < r){
        mid = l + (r - l + 1) / 2;
        if(ok(mid, false))
            l = mid;
        else 
            r = mid - 1;
    }
    ok(l, true);
    return 0;
}