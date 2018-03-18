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

int n, a, b;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    cin >> n >> a >> b;
    if(a == 0 && b == 0){
        for(int i = 0; i < n; ++i)
            printf("%d%c", 1, " \n"[i == n - 1]);
        return 0;
    }
    if(n == 1)
        return 0 * printf("1\n");
    vector<int> v;
    v.push_back(1);
    int sum = 1, lst = 1;
    for(int i = 1; i < n; ++i){
        if(b > 0){
            --b;
            lst = sum + 1;
            v.push_back(lst);
            sum += lst;
        } else if(a > 0){
            if(lst + 1 <= sum){
                --a;
                ++lst;
                v.push_back(lst);
                sum += lst;
            } else{
                v.push_back(lst);
                sum += lst;
            }
        } else{
            v.push_back(1);
        }
    }
    if(a + b > 0)
        return 0 * printf("%d\n", -1);
    for(int i = 0; i < sz(v); ++i)
        if(v[i] > 50000)
            return 0 * printf("-1\n");
    for(int i = 0; i < sz(v); ++i)
        printf("%d%c", v[i], " \n"[i == sz(v) - 1]);
    return 0;
}