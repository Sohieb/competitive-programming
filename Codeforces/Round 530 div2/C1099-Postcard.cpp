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

string str;
int k;
int dp[202][505];

int solve(int i, int has) {
    if (has > 500) return 0;
    if (i == sz(str)) return (has == k);
    int &ret = dp[i][has];
    if (~ret) return ret;
    ret = 0;
    if (str[i] == '?') {
        ret |= solve(i + 1, has);
        ret |= solve(i + 1, has - 1);
    } else if (str[i] == '*') {
        ret |= solve(i + 1, has - 1);
        for (int j = 0; j <= 200; ++j)
            ret |= solve(i + 1, has + j);
    } else {
        ret |= solve(i + 1, has + 1);
    }
    return ret;
}

vector<char> ans;

void printAns(int i, int has) {
    if (i == sz(str)) return;
    if (str[i] == '?') {
        if (solve(i + 1, has)) {
            printAns(i + 1, has);
        } else {
            ans.pop_back();
            printAns(i + 1, has - 1);
        }
    } else if (str[i] == '*') {
        if (solve(i + 1, has - 1)) {
            ans.pop_back();
            printAns(i + 1, has - 1);   
        } else {
            for (int j = 0; j <= 200; ++j)
                if (solve(i + 1, has + j)) {
                    for (int w = 0; w < j; ++w)
                        ans.push_back(str[i-1]);
                    printAns(i + 1, has + j);
                    break;
                }
        }
    } else {
        ans.push_back(str[i]);
        printAns(i + 1, has + 1);
    }
}

int main() {
    cin >> str >> k;
    memset(dp, -1, sizeof dp);
    if (solve(0, 0) == 0)
        return !printf("Impossible\n");
    printAns(0, 0);
    for (int i = 0; i < sz(ans); ++i)
        printf("%c", ans[i]);
    cout << endl;
    return 0;
}
