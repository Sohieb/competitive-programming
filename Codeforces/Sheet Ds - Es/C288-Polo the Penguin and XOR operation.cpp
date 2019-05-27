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
int arr[1000005];
int trie[5000000][2], lstNode;
int cnt[5000000];
string tmp;

int insert(int me, int i) {
    if (i == sz(tmp)) return cnt[me] = 1;
    int nxt = trie[me][tmp[i] - '0'];
    if (nxt == -1) nxt = trie[me][tmp[i] - '0'] = ++lstNode;
    insert(nxt, i + 1);
    return ++cnt[me]; 
}

string best;

void solve(int me, int i) {
    if (i == sz(tmp)) {
        --cnt[me];
        return;
    }
    int nxt = trie[me][tmp[i] - '0'];
    if (nxt != -1 && cnt[nxt]) {
        best += tmp[i];
        solve(nxt, i + 1);
    } else {
        best += char('0' + 1 - tmp[i] + '0');
        solve(trie[me][1 - tmp[i] + '0'], i + 1);
    }
    --cnt[me];
}

int main() {
    scanf("%d", &n);
    memset(trie, -1, sizeof trie);
    for (int i = 0; i <= n; ++i) {
        tmp = "";
        int v = i;
        while (v > 0) {
            tmp += char('0' + (v & 1));
            v /= 2;
        }
        while (sz(tmp) < 21) tmp += '0';
        reverse(all(tmp));
        insert(0, 0);
    }
    ll ans = 0;
    for (int i = 0; i <= n; ++i) {
        tmp = "";
        int v = i;
        while (v > 0) {
            tmp += char('0' + (v & 1));
            v /= 2;
        }
        while (sz(tmp) < 21) tmp += '0';
        reverse(all(tmp));
        for (int j = 0; j < sz(tmp); ++j) 
            tmp[j] = (tmp[j] == '0' ? '1' : '0');
        best = "";
        solve(0, 0);
        v = 0;
        reverse(all(best));
        for (int j = 0; j < sz(best); ++j)
            v += (best[j] == '1') * (1 << j);
        arr[i] = v;
        ans += (v ^ i);
    }
    cout << ans << endl;
    for (int i = 0; i <= n; ++i)
        printf("%d%c", arr[i], " \n"[i==n]);
    return 0;
}
