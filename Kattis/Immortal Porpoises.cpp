#include <bits/stdc++.h>
#include <ext/numeric>

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

const db eps = 1e-9;
const db pi = acos(-1);
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const int mod = 1000 * 1000 * 1000 + 7;

const int matSiz=2;
const int MOD=1000000000;

struct matrix{
  ll mat[matSiz][matSiz];
};

struct MUL{
  matrix operator()(const matrix &a,const matrix &b)const{
    matrix res;
    for(int i=0;i<matSiz;++i)
      for(int j=0;j<matSiz;++j){
        res.mat[i][j]=0;
        for(int k=0;k<matSiz;++k){
          ll tmp=a.mat[i][k]*1LL*b.mat[k][j];
          if(tmp>=MOD)tmp%=MOD;
          res.mat[i][j]+=tmp;
          if(res.mat[i][j]>=MOD)
            res.mat[i][j]-=MOD;
        }
      }
    return res;
  }
};

matrix identity_element(const MUL &){
  matrix res;
  for(int i=0;i<matSiz;++i)
    for(int j=0;j<matSiz;++j)
      res.mat[i][j]=(i==j);
  return res;
}

ll T, a, n;

int main() {
    cin >> T;
    for (int i = 1; i <= T; ++i) {
        cin >> a >> n;
        MUL mul;
        matrix A = {0, 1, 1, 1};
        A = power(A, n, mul);
        matrix B = {0, 0, 1, 0};
        B = mul(A, B);
        cout << a << " " << B.mat[0][0]<<endl;
    }
    return 0;
}
