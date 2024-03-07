#include <bits/stdc++.h>
using namespace std;
/* TYPES  */
// #define int long long
#define pii pair<int, int>
#define F first
#define S second
#define vc vector
#define vi vector<int>
#define vii vector<pii>
#define mii map<int, int>
#define si set<int>
/* UTILS */
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define rev(i, a, b) for (int i = a; i >= b; --i)
#define tomax(a, b) (a) = max((a), (b))
#define tomin(a, b) (a) = min((a), (b))
#define all(a) a.begin(), a.end()
#define rall(a) (a).rbegin(), (a).rend()
#define pob pop_back
#define pb push_back
#define eb emplace_back
#define ins insert
#define err(a) cerr << #a << ": " << a << "\n"
#define sp << " " <<
#define ios ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

int n, q;
bool arr[1003][1003];

struct BIT {
    int bit[1003];

    void modify(int pos, int val) {
        for (; pos <= n; pos += pos & (-pos)) bit[pos] += val;
    }
    int query(int pos) {
        int ans = 0;
        for (; pos > 0; pos -= pos & (-pos)) ans += bit[pos];
        return ans;
    }
};

struct BIT2 {
    BIT bit[1003];

    void modify(int pos_y, int pos_x, int val) {
        for (; pos_y <= n; pos_y += pos_y & (-pos_y))
            bit[pos_y].modify(pos_x, val);
    }
    int query(int pos_y, int pos_x) {
        int ans = 0;
        for (; pos_y > 0; pos_y -= pos_y & (-pos_y))
            ans += bit[pos_y].query(pos_x);
        return ans;
    }
};

signed main() {
    ios;
    cin >> n >> q;
    BIT2 bit;
    char tmp;

    rep(i, 1, n) rep(j, 1, n) cin >> tmp,
        arr[i][j] = (tmp == '*'),
        bit.modify(i, j, arr[i][j]);

    while (q--) {
        int cmd, y1, x1, y2, x2;
        cin >> cmd >> y1 >> x1;
        if (cmd == 1)
            bit.modify(y1, x1, arr[y1][x1] == 1 ? -1 : 1), arr[y1][x1] = (arr[y1][x1])^(1);
        else {
            cin >> y2 >> x2;
            if (x1 < x2) swap(x1, x2);
            if (y1 < y2) swap(y1, y2);
            cout << bit.query(y1, x1) - bit.query(y1, x2 - 1) -
                        bit.query(y2 - 1, x1) + bit.query(y2 - 1, x2 - 1)
                 << '\n';
        }
    }
    return 0;
}