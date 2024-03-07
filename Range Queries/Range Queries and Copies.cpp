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

#define _lc seg[id].lc
#define _rc seg[id].rc
#define M ((L + R) / 2)

int n, q, cur = 0;
vi arr;
vi ls;
struct node {
    int lc, rc, sum = 0;
} seg[200005 * 2 + 200005 * 19];
// build -> 200005*2, modify -> 200005*(log_2(200005)+1)

void build(int L = 0, int R = n, int id = 0) {
    if (L == R - 1) {
        seg[id].sum = arr[L];
    } else {
        seg[id].lc = ++cur, seg[id].rc = ++cur;
        build(L, M, _lc), build(M, R, _rc);
        seg[id].sum = seg[_lc].sum + seg[_rc].sum;
    }
}

void modify(int &id, int pos, int val, int L = 0, int R = n) {
    seg[++cur] = seg[id];
    id = cur;
    if (L == R - 1) {
        seg[id].sum = val;
    } else {
        if (pos >= M)
            modify(_rc, pos, val, M, R);
        else
            modify(_lc, pos, val, L, M);
        seg[id].sum = seg[_lc].sum + seg[_rc].sum;
    }
}

int query(int id, int l, int r, int L = 0, int R = n) {
    if (l == L && r == R) return seg[id].sum;
    if (l >= M) return query(_rc, l, r, M, R);
    if (r <= M) return query(_lc, l, r, L, M);
    return query(_lc, l, M, L, M) + query(_rc, M, r, M, R);
}

signed main() {
    ios;
    cin >> n >> q;
    arr.resize(n);
    ls.eb(0);
    rep(i, 0, n - 1) cin >> arr[i];
    build();
    while (q--) {
        int cmd, a, b, k, x;
        cin >> cmd;
        if (cmd == 1) {
            cin >> k >> a >> x;
            k--, a--;
            modify(ls[k], a, x);
        } else if (cmd == 2) {
            cin >> k >> a >> b;
            k--, a--;
            cout << query(ls[k], a, b) << '\n';
        } else {
            cin >> k;
            ls.eb(ls[--k]);
        }
    }
    return 0;
}