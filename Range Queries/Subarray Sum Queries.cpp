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

int n, q;

struct Nodes {
    int pre, suf, sum, mx;
} seg[200005 * 4];

void pull(int L, int R, int id) {
    if (L == R - 1) return;
    seg[id].pre = max(seg[lc].pre, seg[lc].sum + seg[rc].pre);
    seg[id].suf = max(seg[rc].suf, seg[lc].suf + seg[rc].sum);
    seg[id].sum = seg[lc].sum + seg[rc].sum;
    seg[id].mx = max(max(seg[lc].mx, seg[rc].mx), seg[lc].suf + seg[rc].pre);
}

void modify(int pos, int val, int L = 0, int R = n, int id = 0) {
    if (L == R - 1) {
        seg[id].pre = seg[id].suf = seg[id].sum = seg[id].mx = val;
    } else {
        if (pos >= M)
            modify(pos, val, M, R, rc);
        else
            modify(pos, val, L, M, lc);
        pull(L, R, id);
    }
}

signed main() {
    ios;
    int tmp;
    cin >> n >> q;
    rep(i, 0, n - 1) cin >> tmp, modify(i, tmp);
    while (q--) {
        int a, b;
        cin >> a >> b;
        modify(a - 1, b);
        cout << max((int)0, seg[0].mx) << '\n';
    }
    return 0;
}