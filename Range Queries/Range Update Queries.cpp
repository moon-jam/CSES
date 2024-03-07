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

#define lc id * 2 + 1
#define rc id * 2 + 2
#define M ((L + R) / 2)

struct Nodes {
    int sum, lz;
} seg[200005 * 4];

void modify(int l, int r, int val, int L, int R, int id) {
    if (l == L && r == R) {
        seg[id].lz += val;
    } else {
        if (l >= M)
            modify(l, r, val, M, R, rc);
        else if (r <= M)
            modify(l, r, val, L, M, lc);
        else modify(l, M, val, L, M, lc), modify(M, r, val, M, R, rc);
    }
}

int query(int pos, int L, int R, int id) {
    if (L == R - 1) return seg[id].lz + seg[id].sum;
    if (pos >= M)
        return seg[id].lz + query(pos, M, R, rc);
    else
        return seg[id].lz + query(pos, L, M, lc);
}

signed main() {
    ios;
    int n, q, tmp;
    cin >> n >> q;
    rep(i, 0, n - 1) cin >> tmp, modify(i, i + 1, tmp, 0, n, 0);
    while (q--) {
        int cmd, a, b, c;
        cin >> cmd >> a;
        a--;
        if(cmd == 1) cin >> b >> c, modify(a, b, c, 0, n, 0);
        else cout << query(a, 0, n ,0) << '\n';
    }
    return 0;
}