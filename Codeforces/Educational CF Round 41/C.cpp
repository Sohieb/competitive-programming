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
vector<string> arr[4];
vector<string> v;
int vis[205][205];

int dfs(int i, int j, int c){
    if(i < 0 || j < 0 || i >= n + n || j >= n + n)
        return 0;
    if(vis[i][j]) return 0;
    vis[i][j] = 1;
    // cout << i << " " << j << " " << v[i][j] << " " << c << endl;
    int res = v[i][j] - '0' != c;
    res += dfs(i + 1, j, 1 - c);
    res += dfs(i - 1, j, 1 - c);
    res += dfs(i, j + 1, 1 - c);
    res += dfs(i, j - 1, 1 - c);
    return res;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    cin >> n;
    for(int i = 0; i < 4; ++i){
        string tmp;
        for(int j = 0; j < n; ++j){
            cin >> tmp;
            arr[i].push_back(tmp);
        }
    }
    sort(arr, arr + 4);
    int out = n * n * 2;
    do{
        v.clear();
        for(int i = 0; i < n; ++i){
            string tmp = arr[0][i];
            tmp += arr[1][i];
            v.push_back(tmp);
        }
        for(int i = 0; i < n; ++i){
            string tmp = arr[2][i];
            tmp += arr[3][i];
            v.push_back(tmp);
        }
        memset(vis, 0, sizeof vis);
        //cout << "====\n";
        out = min(out, dfs(0, 0, 0));
        memset(vis, 0, sizeof vis);
        //cout << "====\n";
        out = min(out, dfs(0, 0, 1));
    }while(next_permutation(arr, arr + 4));
    cout << out << endl;
    return 0;
}