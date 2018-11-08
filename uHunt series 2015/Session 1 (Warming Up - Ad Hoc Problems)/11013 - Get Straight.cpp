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

string in[5];
map<char, int> cardValue;
map<char, char> nxt;
vector<string> cards;
double scores[5];

void init() {
    cardValue['A'] = 1;
    cardValue['2'] = 2;
    cardValue['3'] = 3;
    cardValue['4'] = 4;
    cardValue['5'] = 5;
    cardValue['6'] = 6;
    cardValue['7'] = 7;
    cardValue['8'] = 8;
    cardValue['9'] = 9;
    cardValue['T'] = 10;
    cardValue['J'] = 11;
    cardValue['Q'] = 12;
    cardValue['K'] = 13;

    nxt['A'] = '2';
    nxt['2'] = '3';
    nxt['3'] = '4';
    nxt['4'] = '5';
    nxt['5'] = '6';
    nxt['6'] = '7';
    nxt['7'] = '8';
    nxt['8'] = '9';
    nxt['9'] = 'T';
    nxt['T'] = 'J';
    nxt['J'] = 'Q';
    nxt['Q'] = 'K';
    nxt['K'] = 'A';

    for (auto p : nxt) {
        string dummy = string(1, p.first);
        cards.push_back(dummy + "S");
        cards.push_back(dummy + "H");
        cards.push_back(dummy + "D");
        cards.push_back(dummy + "C");
    }
}

bool cmp(string a, string b) {
    return (cardValue[a[0]] <= cardValue[b[0]]);
}

int calc(vector<int> v) {
    sort(all(v));
    if (sz(v) == 0) return 0;
    if (v.back() == 5) return 100;
    if (v.back() == 4) return 10;
    if (v.back() == 3) {
        if (v[0] == 2) return 5;
        return 3;
    }
    if (sz(v) > 1) return 1;
    return 0;
}

int getEarn() {
    string me[10];
    for (int i = 0; i < 5; ++i)
        me[i] = in[i];
    sort(me, me + 5);
    int res = 0;
    do {
        vector<int> match;
        int cur = 1;
        for (int i = 0; i < 5; ++i) {
            if (nxt[me[i][0]] == me[i+1][0]) ++cur;
            else {
                if (cur > 1) match.push_back(cur);
                cur = 1;
            }
        }
        if (cur > 1) match.push_back(cur);
        res = max(res, calc(match));
    }while (next_permutation(me, me + 5));
    return res;
}

int main() {
    init();
    while (cin >> in[0] >> in[1] >> in[2] >> in[3] >> in[4]) {
        memset(scores, 0, sizeof scores);
        int stay = getEarn() - 1;
        double best = stay;
        for (int i = 0; i < 5; ++i) {
            for (int j = 0; j < 52; ++j) {
                if (cards[j] == in[0]) continue;
                if (cards[j] == in[1]) continue;
                if (cards[j] == in[2]) continue;
                if (cards[j] == in[3]) continue;
                if (cards[j] == in[4]) continue;
                string curCard = in[i];
                in[i] = cards[j];
                scores[i] += getEarn();
                in[i] = curCard;
            }
            scores[i] /= 47.0;
            scores[i] -= 2;
            best = max(best, scores[i]);
        }
        if (abs(best - stay) < eps) {
            printf("Stay\n");
            continue;
        }
        for (int i = 0; i < 5; ++i) {
            if (abs(best - scores[i]) < eps) {
                printf("Exchange %s\n", in[i].c_str());
                break;
            }
        }
    }
    return 0;
}
