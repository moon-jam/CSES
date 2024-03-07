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
vi arr;

struct nodes {
    int sum, lz_s, lz_d;
} seg[200005 * 4];

void push(int L, int R, int id) {
    if (seg[id].lz_s == 0 && seg[id].lz_d == 0) return;
    if (L != R - 1) {
        seg[lc].lz_s += seg[id].lz_s;
        seg[lc].lz_d += seg[id].lz_d;
        seg[rc].lz_s += seg[id].lz_s + (M - L) * seg[id].lz_d;
        seg[rc].lz_d += seg[id].lz_d;
    }
    seg[id].sum += (R - L) * (seg[id].lz_s*2 + seg[id].lz_d * (R - L - 1)) / 2;
    seg[id].lz_s = seg[id].lz_d = 0;
}

void pull(int L, int R, int id) {
    if (L == R - 1) return;
    push(L, M, lc), push(M, R, rc);
    seg[id].sum = seg[lc].sum + seg[rc].sum;
}

void build(int L = 0, int R = n, int id = 0) {
    if (L == R - 1) {
        seg[id].sum = arr[L];
    } else {
        build(L, M, lc), build(M, R, rc);
        pull(L, R, id);
    }
}

void modify(int l, int r, int val = 1, int L = 0, int R = n, int id = 0) {
    push(L, R, id);
    if (l == L && r == R) {
        seg[id].lz_s += val;
        seg[id].lz_d++;
    } else {
        if (l >= M)
            modify(l, r, val, M, R, rc);
        else if (r <= M)
            modify(l, r, val, L, M, lc);
        else
            modify(l, M, val, L, M, lc), modify(M, r, val + M - l, M, R, rc);
        pull(L, R, id);
    }
}

int query(int l, int r, int L = 0, int R = n, int id = 0) {
    push(L, R, id);
    if (l == L && r == R) return seg[id].sum;
    if (l >= M) return query(l, r, M, R, rc);
    if (r <= M) return query(l, r, L, M, lc);
    return query(l, M, L, M, lc) + query(M, r, M, R, rc);
}

signed main() {
    ios;
    cin >> n >> q;
    arr.resize(n);
    for (int &i : arr) cin >> i;
    build();
    while (q--) {
        int cmd, a, b;
        cin >> cmd >> a >> b;
        a--;
        if (cmd == 1)
            modify(a, b);
        else
            cout << query(a, b) << '\n';
    }

    return 0;
}
