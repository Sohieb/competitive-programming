#include <bits/stdc++.h>

using namespace std;
using namespace __gnu_cxx;

typedef double db;
typedef long long ll;

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
int n, m;

bitset<100000> isPrime;
vector<int> primes;

void sieve(){
  isPrime.set();
  isPrime[0] = isPrime[1] = 0;
  for(int i = 2; i < 100000; i = i + 1 + (i & 1)){
    if(isPrime[i]){
      primes.push_back(i);
      if(i * 1LL * i > 100000)
        continue;
      for(int j = i * i; j < 100000; j += i)
        isPrime[j] = 0;
    }
  }
}

bool good(int x){
  if(x < 100000)
    return isPrime[x];
  int idx = 0;
  while(primes[idx] * primes[idx] <= x){
    if(x % primes[idx] == 0)
      return 0;
    ++idx;
  }
  return 1;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);
#endif
  sieve();
  sf(T);
  while(T--){
    sf(n), sf(m);
    for(int i = n; i <= m; ++i)
      if(good(i))
        pf(i);
    if(T)pnl;
  }
  return 0;
}
