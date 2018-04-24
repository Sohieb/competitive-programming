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

int N;
int a[200005];
int b[200005];
int c[200005];
int tree[200200];

void init(){
    vector<int> v;
    rep(i, N) v.push_back(a[i + 1]);
    sort(all(v));
    v.resize(unique(all(v)) - v.begin());
    for(int i = 1; i <=N; ++i)
        c[i] = 1 + lower_bound(all(v), a[i]) - v.begin();
}

void add(int x, int v){
    while(x <= N + 5){
        tree[x] += v;
        if(tree[x] >= mod) tree[x] -= mod;
        x += (x & -x);
    }
}

int get(int x){
    int sum = 0;
    while(x){
        sum += tree[x];
        if(sum >= mod) sum -= mod;
        x -= (x & -x);
    }
    return sum;
}

int main() {
#ifndef ONLINE_JUDGE
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    scanf("%d", &N);
    for(int i = 1; i <= N; ++i) scanf("%d", &a[i]);
    init();
    int out = 0;
    for(int i = 1; i <= N; ++i){
        b[i] = i + get(c[i] - 1);
        if(b[i] >= mod) b[i] -= mod;
        add(c[i], b[i]);
        b[i] += b[i - 1];
        if(b[i] >= mod) b[i] -= mod;
        out += b[i];
        if(out >= mod) out -= mod;
    }
    printf("%d\n", out);
	return 0;
}
