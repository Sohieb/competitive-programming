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
string str;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    cin >> n;
    while(n--){
        cin >> str;
        int a = 0, b = 0, c = 0;
        for(auto ch : str){
            if(isalpha(ch)) ++a;
            if(isdigit(ch)) ++b;
            if(ch == '@' || ch == '?' || ch == '!') ++c;
        }
        if(a >= 4 && b >= 4 && c >= 2)
            puts("The last character can be any type.");
        else if(a == 3)
            puts("The last character must be a letter.");
        else if(b == 3)
            puts("The last character must be a digit.");
        else
            puts("The last character must be a symbol.");
    }
    return 0;
}
