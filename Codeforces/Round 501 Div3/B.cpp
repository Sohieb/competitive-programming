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

int n, cnt[26];
string s, t;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    cin >> n >> s >> t;
    for(auto c : s)
        cnt[c - 'a']++;
    for(auto c : t)
        if(!cnt[c - 'a'])
            return !printf("-1\n");
        else cnt[c - 'a']--;
    vector<int> ans;
    int j = n - 1;
    while(j >= 0){
        if(t[j] == s[j]){
            --j;
            continue;
        }
        for(int i = j - 1; i >= 0; --i)
            if(s[i] == t[j]){
                swap(s[i], s[i + 1]);
                ans.push_back(i + 1);
                break;
            }
    }
    printf("%d\n", sz(ans));
    for(int i = 0; i < sz(ans); ++i)
        printf("%d%c", ans[i], " \n"[i == sz(ans) - 1]);
    return 0;
}
