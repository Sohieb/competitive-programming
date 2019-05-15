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

int a[] = {4, 8, 15, 16, 23, 42};
map<int, pair<int, int> > mp;
int b[6];

int main() {
    for (int i = 0; i < 6; ++i)
    	for (int j = i + 1; j < 6; ++j)
    		mp[a[i] * a[j]] = {a[i], a[j]};
    int tmp;
    cout << "? " << 1 << " " << 2 << endl;
    fflush(stdout);
    cin >> tmp;
    pii p1 = mp[tmp];
    cout << "? " << 1 << " " << 3 << endl;
    fflush(stdout);
    cin >> tmp;
    pii p2 = mp[tmp];
    if (p1.F == p2.F) {
    	b[0] = p1.F;
    	b[1] = p1.S;
    	b[2] = p2.S;
    } else if (p1.F == p2.S) {
    	b[0] = p1.F;
    	b[1] = p1.S;
    	b[2] = p2.F;
    } else if (p1.S == p2.F) {
    	b[0] = p1.S;
    	b[1] = p1.F;
    	b[2] = p2.S;
    } else {
    	b[0] = p1.S;
    	b[1] = p1.F;
    	b[2] = p2.F;
    }


    cout << "? " << 4 << " " << 5 << endl;
    fflush(stdout);
    cin >> tmp;
    p1 = mp[tmp];
    cout << "? " << 4 << " " << 6 << endl;
    fflush(stdout);
    cin >> tmp;
    p2 = mp[tmp];
    if (p1.F == p2.F) {
    	b[3] = p1.F;
    	b[4] = p1.S;
    	b[5] = p2.S;
    } else if (p1.F == p2.S) {
    	b[3] = p1.F;
    	b[4] = p1.S;
    	b[5] = p2.F;
    } else if (p1.S == p2.F) {
    	b[3] = p1.S;
    	b[4] = p1.F;
    	b[5] = p2.S;
    } else {
    	b[3] = p1.S;
    	b[4] = p1.F;
    	b[5] = p2.F;
    }
    cout << "!";
    fflush(stdout);
    for (int i = 0; i < 6; ++i) {
    	cout << " " << b[i];
    	fflush(stdout);
    }
    cout << endl;
    fflush(stdout);
    return 0;
}