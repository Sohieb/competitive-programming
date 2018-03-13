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

char str[1505];
char bad[27];
int k;

const int SIZ = 1500 * 1500 / 2;
int isBad[26];
int trie[SIZ][26], lst;

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);
#endif
  	scanf("%s%s%d", str, bad, &k);
  	for(int i = 0; i < 26; ++i)
  		isBad[i] = 1 - bad[i] + '0';
  	memset(trie, -1, sizeof trie);
  	for(int i = 0; str[i]; ++i){
  		int can = 0;
  		int me = 0;
  		for(int j = i; str[j]; ++j){
  			can += isBad[str[j] - 'a'];
  			if(can > k) break;
  			int nxt = trie[me][str[j] - 'a'];
  			if(~nxt)
  				me = nxt;
  			else
  				trie[me][str[j] - 'a'] = ++lst,
  				me = lst;
  		}
  	}
  	printf("%d\n", lst);
	return 0;
}