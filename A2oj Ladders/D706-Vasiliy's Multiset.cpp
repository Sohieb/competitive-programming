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

int q, x;
char c;
int trie[6000000][2], lst;
int isEnd[6000000];

void init(){
    memset(trie, -1, sizeof trie);
}

string conv(int a){
    string s;
    while(a)
        s += ('0' + a % 2),
        a /= 2;
    while(sz(s) < 32) s += '0';
    reverse(all(s));
    return s;
}

void insert(string s){
    int me = 0;
    isEnd[me]++;
    for(int i = 0; i < sz(s); ++i){
        int &nxt = trie[me][s[i] - '0'];
        if(nxt == -1)
            nxt = ++lst;
        me = nxt;
        isEnd[me]++;
    }
}

void remove(string s){
    int me = 0;
    isEnd[me]--;
    for(int i = 0; i < sz(s); ++i){
        int &nxt = trie[me][s[i] - '0'];
        me = nxt;
        isEnd[me]--;
    }
}

int findMax(string str){
    int res = 0, j = 31;
    int me = 0;
    for(int i = 0; i < sz(str); ++i){
        int nxt = trie[me][1 - str[i] + '0'];
        if(~nxt && isEnd[nxt] > 0){
            if(str[i] == '0')
                res += (1 << j);
        }else{
            if(str[i] == '1')
                res += (1 << j);
            nxt = trie[me][str[i] - '0'];
        }
        me = nxt;
        --j;
    }
    return res;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);
#endif
    init();
    insert(conv(0));
    sf(q);
    while(q--){
        scanf(" %c%d", &c, &x);
        if(c == '+'){
            insert(conv(x));
        }else if(c == '-'){
            remove(conv(x));
        }else{
            printf("%d\n", x ^ findMax(conv(x)));
        }
    }
    return 0;
}