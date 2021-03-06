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

string str;
int cnt[26];

long long get(int md){
    long long tmp = 0;
    for(int i = 0; i < 26; ++i){
        tmp += (cnt[i] % md) * 1LL * cnt[i];
    }
    return tmp;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    cin >> str;
    for(int i = 0; i < sz(str); ++i)
        cnt[str[i] - 'a']++;
    int res = 2;
    long long cost = LL_INF;
    for(int i = 2; i <= sz(str); ++i){
        long long c = get(i);
        if(c < cost)
            cost = c, res = i;
    }
    cout << res << endl;
    return 0;
}