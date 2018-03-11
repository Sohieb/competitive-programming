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

vector<int> z_function(string s){
    int n = sz(s);
    vector<int> z(n);
    for(int i = 1, l = 0, r = 0; i < n; ++i){
        if(i <= r) z[i] = min(r - i + 1, z[i - l]);
        while(i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if(i + z[i] - 1 > r)
            l = i, r = i + z[i] -1;
    }
    return z;
}

char s1[100005], s2[100005];
int dv[100005];
int match[100005];

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);
#endif
    scanf("%s%s", s1, s2);
    if(strlen(s1) > strlen(s2))
        swap(s1, s2);
    vector<int> z1 = z_function(s1);
    vector<int> z2 = z_function(s2);
    int n1 = sz(z1), n2 = sz(z2);
    dv[n1]++;
    dv[n2]++;
    for(int i = 1; s1[i]; ++i)
        if(i + z1[i] == n1 && n1 % i == 0)
            ++dv[i];
    for(int i = 1; s2[i]; ++i)
        if(i + z2[i] == n2 && n2 % i == 0)
            ++dv[i];
    for(int i = 0; i < min(n1, n2); ++i)
        if(s1[i] == s2[i])
            match[i] = 1;
        else
            break;
    match[min(n1, n2)] = match[min(n1, n2) - 1];
    int res = 0;
    for(int i = 0; i <= min(n1, n2); ++i)
        if(dv[i] == 2 && match[i])
            ++res;
    pf(res);
	return 0;
}