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

int T;
int n, q;
int trie[3000000][2], lst;
int isEnd[3000000];

void init(){
    memset(trie, -1, sizeof trie);
    memset(isEnd, -1, sizeof isEnd);
    lst = 0;
}

string conv(int x){
    string s = "";
    while(x)
        s += ('0' + x % 2),
        x /= 2;
    while(sz(s) < 32) s += '0';
    reverse(all(s));
    return s;
}

void insert(string s, int idx){
    int me = 0;
    for(int i = 0; i < sz(s); ++i){
        int &nxt = trie[me][s[i] - '0'];
        if(nxt == -1)
            nxt = ++lst;
        me = nxt;
    }
    if(isEnd[me] == -1)
        isEnd[me] = idx;
}

int find(string s){
    int me = 0;
    for(int i = 0; i < sz(s); ++i){
        int &nxt = trie[me][1 - s[i] + '0'];
        if(~nxt){
            me = nxt;
        } else{
            me = trie[me][s[i] - '0'];
        }
    }
    return isEnd[me];
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);
#endif
    sf(T);
    while(T--){
        init();
        sf(n), sf(q);
        for(int i = 0; i < n; ++i){
            int a;
            sf(a);
            insert(conv(a), i);
        }
        while(q--){
            int a;
            sf(a);
            printf("%d\n", find(conv(a)) + 1);
        }
        printf("\n");
    }
    return 0;
}