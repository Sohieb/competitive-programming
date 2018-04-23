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

int K, N;
string in[2505];
char sss[5050];
int cnt1[26], cnt2[26];
vector<int> mis[2505];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    scanf("%d%d", &K, &N);
    for(int i = 0; i < K; ++i){
        scanf("%s", sss);
        in[i] = string(sss);
    }
    for(int i = 0; i < N; ++i) cnt1[in[0][i] - 'a']++;
    for(int i = 1; i < K; ++i){
        for(int j = 0; j < 26; ++j) cnt2[j] = 0;
        for(int j = 0; j < N; ++j) cnt2[in[i][j] - 'a']++;
        for(int j = 0; j < 26; ++j) if(cnt1[j] != cnt2[j]) return !printf("-1\n");
    }
    bool canZ = false;
    for(int i = 0; i < 26; ++i) if(cnt1[i] > 1) canZ = true;
    for(int i = 1; i < K; ++i){
        for(int j = 0; j < N; ++j) if(in[0][j] != in[i][j]) mis[i].push_back(j);
        if(sz(mis[i]) > 4) return !printf("-1\n");
    }
    for(int i = 0; i < N; ++i)
        for(int j = i + 1; j < N; ++j){
            swap(in[0][i], in[0][j]);
            int good = 0;
            for(int k = 1; k < K; ++k){
                int bad = 0;
                if(in[0][i] != in[k][i]) ++bad;
                if(in[0][j] != in[k][j]) ++bad;
                for(auto it : mis[k]) if(it != i && it != j && in[0][it] != in[k][it]) ++bad;
                if(bad > 2) break;
                if(bad == 0 && !canZ) break;
                ++good;
            }
            if(good == K - 1) return !printf("%s\n", in[0].c_str());
            swap(in[0][i], in[0][j]);
        }
    printf("-1\n");
	return 0;
}
