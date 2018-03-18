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
char str[200005];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#endif
	scanf("%d%s", &n, str);
    set<int> d, r;
    for(int i = 0; str[i]; ++i)
        if(str[i] == 'D') d.insert(i);
        else r.insert(i);
    while(!d.empty() && !r.empty()){
        for(int i = 0; i < n; ++i){
            if(d.empty() || r.empty())
                break;
            if(str[i] == 'D'){
                if(d.find(i) == d.end())
                    continue;
                set<int>::iterator it = r.lower_bound(i);
                if(it == r.end())
                    it = r.begin();
                r.erase(it);
            }else{
                if(r.find(i) == r.end())
                    continue;
                set<int>::iterator it = d.lower_bound(i);
                if(it == d.end())
                    it = d.begin();
                d.erase(it);
            }
        }
    }
    if(d.empty())
        printf("R\n");
    else
        printf("D\n");
    return 0;
}