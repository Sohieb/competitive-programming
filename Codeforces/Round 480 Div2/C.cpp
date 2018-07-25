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

int n, k;
int a[100005];
set<pii> st;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    scanf("%d%d", &n, &k);
    for(int i = 0; i < 257; ++i)
        st.insert({i, i});
    for(int i = 0; i < n; ++i){
        scanf("%d", &a[i]);
        set<pii>::iterator it = st.lower_bound({a[i] + 1, a[i]});
        --it;
        while(it != st.begin()){
            set<pii>::iterator it2 = it;
            --it2;
            pii p1 = *it, p2 = *it2;
            if(p1.S - p2.F + 1 > k)
                break;
            st.erase(p1);
            st.erase(p2);
            pii nw = {it2->F, it->S};
            st.insert(nw);
            it = st.lower_bound({a[i] + 1, a[i]});
            --it;
        }
    }
    for(int i = 0; i < n; ++i){
        set<pii>::iterator it = st.lower_bound({a[i] + 1, a[i]});
        --it;
        printf("%d%c", it->F, " \n"[i == n-1]);
    }
    return 0;
}
