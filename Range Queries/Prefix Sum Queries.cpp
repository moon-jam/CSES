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
    int mx, lz;
} seg[200005 * 4];

int arr[200005];
int n, q;

void push(int L, int R, int id) {
    if (L != R - 1) {
        seg[lc].lz += seg[id].lz;
        seg[rc].lz += seg[id].lz;
    }
    seg[id].mx += seg[id].lz;
    seg[id].lz = 0;
}

void pull(int L, int R, int id) {
    if (L == R - 1) return;
    push(L, M, lc), push(M, R, rc);
    seg[id].mx = max(seg[lc].mx, seg[rc].mx);
}

void modify(int l, int r, int val, int L = 0, int R = n, int id = 0) {
    push(L, R, id);
    if (L == l && R == r) {
        seg[id].lz += val;
    } else {
        if (l >= M)
            modify(l, r, val, M, R, rc);
        else if (r <= M)
            modify(l, r, val, L, M, lc);
        else
            modify(l, M, val, L, M, lc), modify(M, r, val, M, R, rc);
        pull(L, R, id);
    }
}

int query(int l, int r, int L = 0, int R = n, int id = 0) {
    push(L, R, id);
    if (l == L && r == R) return seg[id].mx;
    if (l >= M) return query(l, r, M, R, rc);
    if (r <= M) return query(l, r, L, M, lc);
    return max(query(l, M, L, M, lc), query(M, r, M, R, rc));
}

signed main() {
    ios;
    cin >> n >> q;
    rep(i, 0, n - 1) cin >> arr[i], modify(i, n, arr[i]);
    while (q--) {
        int cmd, a, b;
        cin >> cmd >> a >> b;
        a--;
        if (cmd == 1)
            modify(a, n, b - arr[a]), arr[a] = b;
        else if (a == 0)
            cout << max((int)0, arr[0]);
        else
            cout << max((int)0, query(a, b) - query(a - 1, a)) << '\n';
    }
    return 0;
}