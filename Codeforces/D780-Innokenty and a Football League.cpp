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

int n;
string s1, s2;
string ans[1010];
pair<string, string> arr[1010];
map<string, bool> taken;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        cin >> s1 >> s2;
        arr[i].F = s1.substr(0, 3);
        arr[i].S = s1.substr(0, 2);
        arr[i].S += s2[0];
    }
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j) {
            if (arr[i].F == arr[j].F) {
                ans[i] = arr[i].S;
                ans[j] = arr[j].S;
                taken[ans[i]] = taken[ans[j]] = 1;
            }
        }


    for (int k = 0; k < n; ++k)
        for (int i = 0; i < n; ++i) {
            if (taken.count(arr[i].F)) {
                ans[i] = arr[i].S;
                taken[ans[i]] = 1;
            }
        }
    set<string> final;
    for (int i = 0; i < n; ++i) {
        if (ans[i] == "") ans[i] = arr[i].F;
        final.insert(ans[i]);
    }
    if (sz(final) < n)
        return !printf("NO\n");
    printf("YES\n");
    for (int i = 0; i < n; ++i)
        printf("%s\n", ans[i].c_str());
    return 0;
}
