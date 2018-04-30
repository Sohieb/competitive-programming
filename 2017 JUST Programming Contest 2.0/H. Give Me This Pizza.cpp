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

int n;
int a[100005];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    sf(n);
    for(int i = 0; i < n; ++i)
        sf(a[i]);
    stack<int> st;
    vector<int> res;
    for(int i = n - 1; i >= 0; --i){
        while(!st.empty() && st.top() <= a[i])
            st.pop();
        if(st.empty()) res.push_back(-1);
        else res.push_back(st.top());
        st.push(a[i]);
    }
    reverse(all(res));
    for(int i = 0; i < n; ++i)
        printf("%d%c", res[i], " \n"[i == n - 1]);
    return 0;
}
