#include <bits/stdc++.h>
//#include <ext/hash_map>
using namespace std;
using namespace __gnu_cxx;

#define EPS      1e-9
#define F        first
#define S        second
#define pi       acos(-1)
#define ll       long long
#define inf      0x3f3f3f3f
#define sz(x)    (int)x.size()
#define sc(x)    scanf("%d",&x)
#define all(x)   x.begin(),x.end()
#define rall(x)  x.rbegin(),x.rend()

int n,m,a,s;

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);
#endif
  sc(n);
  for(int i=0;i<n;++i)
    sc(a),s+=a;
  sc(m);
  int res=1000000;
  for(int i=0;i<m;++i){
    int l,r;
    sc(l),sc(r);
    if(s>=l&&s<=r)res=s;
    else if(s<=r)res=min(res,l);
  }
  if(res==1000000)puts("-1");
  else printf("%d\n",res);
  return 0;
}