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

int n;
string arr[500005];
char tmp[11];
int dp[26][26];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#endif
	scanf("%d", &n);
    for(int i = 0; i < n; ++i){
        scanf("%s", tmp);
        arr[i] = tmp;
    }
    for(int i = 0; i < n; ++i){
        int l = arr[i][0] - 'a';
        int r = arr[i][sz(arr[i]) - 1] - 'a';
        //dp[l][r] = max(dp[l][r], sz(arr[i]));
        for(int j = 0; j < 26; ++j){
            // if(l == r && j == l) continue;
            if(dp[j][l])
                dp[j][r] = max(dp[j][r], dp[j][l] + sz(arr[i]));
        }
        dp[l][r] = max(dp[l][r], sz(arr[i]));
    }
    int out = 0;
    for(int i = 0; i < 26; ++i)
        out = max(out, dp[i][i]);
    cout << out << endl;
    return 0;
}