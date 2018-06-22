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

int n, m;
int a[200005];
int d[200005];
set<int> st;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; ++i)
        st.insert(i);
    int mx = n / m;
    ll out = 0;
    for(int i = 0; i < n; ++i){
        sf(a[i]);
        if(d[a[i] % m] < mx){
            ++d[a[i] % m];
            if(d[a[i] % m] == mx)
                st.erase(a[i] % m);
            continue;
        }
        set<int>::iterator it = st.lower_bound(a[i] % m);
        if(it == st.end()) it = st.begin();
        int dif;
        if(*it > a[i] % m){
            dif = *it - a[i] % m;
        }else{
            dif = m - a[i] % m + *it;
        }
        a[i] += dif;
        out += dif;
        ++d[a[i] % m];
        if(d[a[i] % m] == mx)
            st.erase(a[i] % m);
    }
    printf("%lld\n", out);
    for(int i = 0; i < n; ++i)
        printf("%d%c", a[i], " \n"[i == n - 1]);
    return 0;
}
