/*
A good implementation for Convex Hull
This is the solution for https://open.kattis.com/problems/convexhull
*/
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

const db eps = 1e-9;
const db pi = acos(-1);
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const int mod = 1000 * 1000 * 1000 + 7;


typedef pair<long long, long long> point;

long long cross(const point &a, const point &b, const point &c) {
    return (b.F - a.F) * (c.S - a.S) - (b.S - a.S) * (c.F - a.F);
}

vector<point> convexHull(vector<point> points) {
    if (points.size() <= 1)
        return points;
    sort(points.begin(), points.end());
    vector<point> h;
    for (auto p: points) {
        while (h.size() >= 2 && cross(h.end()[-2], h.back(), p) >= 0)
            h.pop_back();
        h.push_back(p);
    }
    reverse(points.begin(), points.end());
    int len1 = h.size();
    for (auto p: points) {
        while (h.size() > len1 && cross(h.end()[-2], h.back(), p) >= 0)
            h.pop_back();
        h.push_back(p);
    }
    h.resize(h.size() - 1 - (h[0] == h[1]));
    return h;
}

int main() {
    int n;
    while (scanf("%d", &n), n > 0) {
        vector<point> arr;
        for (int i = 0, x, y; i < n; ++i) {
            scanf("%d%d", &x, &y);
            arr.push_back({x, y});
        }
        vector<point> hull = convexHull(arr);
        reverse(all(hull));
        printf("%d\n", sz(hull));
        for (int i = 0; i < sz(hull); ++i)
            printf("%lld %lld\n", hull[i].F, hull[i].S);
    }
}
