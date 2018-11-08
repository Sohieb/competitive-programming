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

int T;
char s[105], t[105];

int main() {
    scanf("%d", &T);
    for (int C = 1; C <= T; ++C) {
        scanf("%s%s", s, t);
        int z1 = 0, z2 = 0;
        for (int i = 0; s[i]; ++i)
            z1 += (s[i] != '1');
        for (int i = 0; t[i]; ++i)
            z2 += (t[i] != '1');
        if (z1 < z2 || strlen(s) != strlen(t)) {
            printf("Case %d: %d\n", C, -1);
            continue;
        }
        z1 = 0;
        for (int i = 0; s[i]; ++i)
            z1 += (s[i] == '0');
        int out = 0;
        bool dummy = true;
        while (z1 < z2 && dummy) {
            dummy = 0;
            for (int i = 0; s[i]; ++i) 
                if (s[i] == '?' && t[i] == '0') {
                    s[i] = '0';
                    ++z1;
                    ++out;
                    dummy = 1;
                    break;
                }
        }
        dummy = 1;
        while (z1 < z2 && dummy) {
            dummy = 0;
            for (int i = 0; s[i]; ++i) 
                if (s[i] == '?') {
                    s[i] = '0';
                    ++z1;
                    ++out;
                    dummy = 1;
                    break;
                }
        }
        for (int i = 0; s[i]; ++i)
            if (s[i] == '?') s[i] = '1', ++out;
        dummy = 1;
        while (z1 > z2 && dummy) {
            dummy = 0;
            for (int i = 0; s[i]; ++i) 
                if (s[i] == '0' && t[i] == '1') {
                    s[i] = '1';
                    --z1;
                    ++out;
                    dummy = 1;
                    break;
                }
        }
        dummy = 1;
        while (z1 > z2 && dummy) {
            dummy = 0;
            for (int i = 0; s[i]; ++i) 
                if (s[i] == '0') {
                    s[i] = '1';
                    --z1;
                    ++out;
                    dummy = 1;
                    break;
                }
        }
        int bad = 0;
        for (int i = 0; s[i]; ++i)
            bad += (s[i] != t[i]);
        out += bad / 2;
        printf("Case %d: %d\n", C, out);
    }
    return 0;
}
