#include <bits/stdc++.h>
using namespace std;
/* TYPES  */
#define int long long
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

#define lc id * 2 + 1
#define rc id * 2 + 2
#define M ((L + R) / 2)

int seg[200005 * 4][3];  // left->0, right->1

void pull(int side, int L, int R, int id) {
    seg[id][side] = min(seg[lc][side], seg[rc][side]);
}

void modify(int pos, int val, bool side, int L = 0, int R = n, int id = 0) {
    if (L == R - 1) {
        seg[id][side] = val + (side ? L : -L);
    } else {
        if (pos >= M)
            modify(pos, val, side, M, R, rc);
        else
            modify(pos, val, side, L, M, lc);
        pull(side, L, R, id);
    }
}

int query(int l, int r, bool side, int L = 0, int R = n, int id = 0) {
    if(l==r) return 0;
    if (l == L && r == R) return seg[id][side];
    if (l >= M) return query(l, r, side, M, R, rc);
    if (r <= M) return query(l, r, side, L, M, lc);
    return min(query(l, M, side, L, M, lc), query(M, r, side, M, R, rc));
}

signed main() {
    ios;
    cin >> n >> q;
    rep(i, 0, 200000 * 4) seg[i][0] = seg[i][1] = 1e9;
    int tmp;
    rep(i, 0, n - 1) cin >> tmp, modify(i, tmp, 0), modify(i, tmp, 1);
    while (q--) {
        int cmd, a, b;
        cin >> cmd >> a;
        a--;
        if (cmd == 1)
            cin >> b, modify(a, b, 0), modify(a, b, 1);
        else
            cout << min(a + query(0, a+1, 0), query(a, n, 1) - a) << '\n';
    }
    return 0;
}