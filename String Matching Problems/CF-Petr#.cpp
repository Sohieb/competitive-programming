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

char str[2020], pre[2020], suf[2020];
int lcp1[2020], lcp2[2020];

const int trieSz = 2000000;
int trie[trieSz][26], lst;
int isEnd[trieSz];

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);
#endif
    scanf("%s%s%s", str, pre, suf);
    int nStr = strlen(str);
    int nPre = strlen(pre);
    int nSuf = strlen(suf);
    for(int i = 0; str[i]; ++i){
        int j = 0;
        while(j < nPre && i + j < nStr && str[i + j] == pre[j])
            ++lcp1[i], ++j;
    }
    for(int i = 0; str[i]; ++i){
        int j = 0;
        while(nSuf - j - 1 >= 0 && i - j >= 0 && str[i - j] == suf[nSuf - j - 1])
            ++lcp2[i], ++j;
    }
    int res = 0;
    memset(trie, -1, sizeof trie);
    for(int i = 0; str[i]; ++i){
    	int me = 0;
    	for(int j = i; str[j]; ++j){
    		int nxt = trie[me][str[j] - 'a'];
    		if(nxt == -1)
    			trie[me][str[j] - 'a'] = ++lst, nxt = lst;
    		me = nxt;
    		if(j - i + 1 < max(nPre, nSuf))
    			continue;
    		if(lcp1[i] == nPre && lcp2[j] == nSuf)
    			res += (isEnd[me] == 0),
    			isEnd[me] = 1;
    	}
    }
    printf("%d\n", res);
    return 0;
}