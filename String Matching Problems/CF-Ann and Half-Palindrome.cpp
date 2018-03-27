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

int n, k;
char str[5005];
int dp[5005][5005];
int trie[12500000][2], lst;
int cnt[12500000];

int solve(int i, int j){
    if(j <= i)
        return 1;
    int &ret = dp[i][j];
    if(~ret) return ret;
    ret = solve(i + 2, j - 2) * (str[i] == str[j]);
    return ret;
}

int fixTrie(int me){
    if(~trie[me][0])
        cnt[me] += fixTrie(trie[me][0]);
    if(~trie[me][1])
        cnt[me] += fixTrie(trie[me][1]);
    return cnt[me];
}

void printAns(int me, int rem){
    int onlyMe = cnt[me];
    if(~trie[me][0]) onlyMe -= cnt[trie[me][0]];
    if(~trie[me][1]) onlyMe -= cnt[trie[me][1]];
    rem -= onlyMe;
    if(rem <= 0) return;
    if(~trie[me][0] && cnt[trie[me][0]] >= rem){
        printf("a");
        printAns(trie[me][0], rem);
    } else {
        printf("b");
        printAns(trie[me][1], rem - 
            (trie[me][0] == -1 ? 0 : cnt[trie[me][0]]));
    }
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#endif
	scanf("%s%d", str, &k);
    n = strlen(str);
    memset(dp, -1, sizeof dp);
    memset(trie, -1, sizeof trie);
    for(int i = 0; i < n; ++i){
        int good = 0;
        for(int j = n - 1; j >= i; --j)
            good += solve(i, j);
        int me = 0;
        for(int j = i; j < n; ++j){
            if(good == 0) break;
            int nxt = trie[me][str[j] - 'a'];
            if(nxt == -1)
                nxt = trie[me][str[j] - 'a'] = ++lst;
            me = nxt;
            if(solve(i, j)){
                --good;
                cnt[me]++;
            }
        }
    }
    fixTrie(0);
    printAns(0, k);
    return 0;
}