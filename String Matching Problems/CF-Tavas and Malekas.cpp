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

vector<int> z_function(string s){
    int n = sz(s);
    vector<int> z(n);
    for(int i = 1, l = 0, r = 0; i < n; ++i){
        if(i <= r) z[i] = min(r - i + 1, z[i - l]);
        while(i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if(i + z[i] -1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}

ll pwr26(int x){
    ll res = 1;
    while(x--)
        res = res * 26 % mod;
    return res;
}

int n, m;
char p[1000005];
int a[1000005];

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);
#endif
    sf(n), sf(m);
    scanf("%s", p);
    for(int i = 0; i < m; ++i)
        sf(a[i]), --a[i];
    vector<int> z = z_function(p);
    z[0] = sz(z);
    multiset<int> st;
    for(int i = 0; i < m; ++i){
        multiset<int>::iterator it = st.lower_bound(a[i]);
        if(it == st.end()){
            st.insert(a[i]);
            st.insert(a[i] + sz(z) - 1);
            continue;
        }
        int x = *--it;
        st.erase(it);
        it = st.lower_bound(a[i]);
        int y = *it;
        st.erase(it);
        int idx = sz(z) - y + a[i] - 1;
        if(idx + z[idx] != sz(z))
            return 0 * printf("0\n");
        st.insert(x);
        st.insert(a[i] + sz(z) - 1);
    }
    int cntFree = n;
    while(sz(st) > 0){
        int x = *st.begin();
        st.erase(st.begin());
        int y = *st.begin();
        st.erase(st.begin());
        cntFree -= y - x + 1;
    }
    cout << pwr26(cntFree) << endl;
    return 0;
}