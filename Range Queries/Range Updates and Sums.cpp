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
#define si _set<int>
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
    int info, add, _set;
} seg[4 * 200005];
 
int arr[200005];
 
void pull(int id) { seg[id].info = seg[lc].info + seg[rc].info; }
 
void push(int L, int R, int id) {
    if (seg[id]._set) {
        if (R != L + 1) seg[lc]._set = seg[rc]._set = seg[id]._set;
        if (R != L + 1) seg[lc].add = seg[rc].add = 0;
        seg[id].info = seg[id]._set * (R - L);
        seg[id]._set = 0;
    }
    if (seg[id].add) {
        if (R != L + 1) seg[lc].add += seg[id].add;
        if (R != L + 1) seg[rc].add += seg[id].add;
        seg[id].info += seg[id].add * (R - L);
        seg[id].add = 0;
    }
}
 
void build(int L, int R, int id) {
    seg[id].add = seg[id]._set = 0;
    if (L == R - 1) {
        seg[id].info = arr[L];
        return;
    }
    build(L, M, lc), build(M, R, rc);
    pull(id);
}
 
void add(int l, int r, int val, int L, int R, int id) {
    push(L, R, id);
    if (r <= L || l >= R) return;
    if (l == L && R == r) {
        seg[id].add += val;
        push(L, R, id);
        return;
    }
    if (l >= M) add(l, r, val, M, R, rc), push(L, M, lc);
    else if (r <= M) add(l, r, val, L, M, lc), push(M, R, rc);
    else add(l, M, val, L, M, lc), add(M, r, val, M, R, rc);
    pull(id);
}
 
void _set(int l, int r, int val, int L, int R, int id) {
    push(L, R, id);
    if (r <= L || l >= R) return;
    if (l == L && R == r) {
        seg[id]._set = val;
        push(L, R, id);
        return;
    }
    if (l >= M) _set(l, r, val, M, R, rc), push(L, M, lc);
    else if (r <= M) _set(l, r, val, L, M, lc), push(M, R, rc);
    else _set(l, M, val, L, M, lc), _set(M, r, val, M, R, rc);
    pull(id);
}
 
int query(int l, int r, int L, int R, int id) {
    push(L, R, id);
    if (l == L && r == R) return seg[id].info;
    if (l >= M) return query(l, r, M, R, rc);
    if (r <= M) return query(l, r, L, M, lc);
    return query(l, M, L, M, lc) + query(M, r, M, R, rc);
}
 
signed main() {
    ios;
    int n, q;
    cin >> n >> q;
    rep(i, 0, n - 1) cin >> arr[i];
    build(0, n, 0);
    while (q--) {
        int cmd, a, b, x;
        cin >> cmd >> a >> b;
        a--;
        if (cmd == 1) cin >> x, add(a, b, x, 0, n, 0);
        if (cmd == 2) cin >> x, _set(a, b, x, 0, n, 0);
        if (cmd == 3) cout << query(a, b, 0, n, 0) << '\n';
    }
    return 0;
}
