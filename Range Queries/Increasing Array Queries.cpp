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
vi pre;
vi arr;

#define lc id * 2
#define rc id * 2 + 1
#define M ((L + R) / 2)

struct nodes {
    int sum, lz;
} seg[200005 * 4];

void push(int L, int R, int id) {
    if (seg[id].lz == 0) return;
    if (L != R - 1) seg[lc].lz = seg[rc].lz = seg[id].lz;
    seg[id].sum = seg[id].lz * (R - L);
    seg[id].lz = 0;
}

void pull(int L, int R, int id) {
    if (L == R - 1) return;
    push(L, M, lc), push(M, R, rc);
    seg[id].sum = seg[lc].sum + seg[rc].sum;
}

void modify(int l, int r, int val, int L = 1, int R = n + 1, int id = 1) {
    push(L, R, id);
    if (l == L && r == R) {
        seg[id].lz = val;
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

int query(int l, int r, int L = 1, int R = n + 1, int id = 1) {
    push(L, R, id);
    if (l == L && r == R)
        return seg[id].sum;
    else if (l >= M)
        return query(l, r, M, R, rc);
    else if (r <= M)
        return query(l, r, L, M, lc);
    return query(l, M, L, M, lc) + query(M, r, M, R, rc);
}

int sum(int l, int r) { return pre[r - 1] - pre[l - 1]; }

signed main() {
    ios;
    cin >> n >> q;
    pre.resize(n + 1), arr.resize(n + 1);
    pre[0] = 0;
    rep(i, 1, n) cin >> arr[i], modify(i, i + 1, arr[i]),
        pre[i] = pre[i - 1] + arr[i];
    vector<pair<pii, int>> qs(q);
    rep(i, 0, q - 1) cin >> qs[i].F.F >> qs[i].F.S, qs[i].S = i;
    sort(all(qs), [](auto a, auto b) { return a.F.F > b.F.F; });
    vi ans(q);
    vii mx;
    int cur = n;
    mx.eb(1e10, n+1);
    for (auto i : qs) {
        int l = i.F.F;int r = i.F.S;int id = i.S;
        while (cur >= l) {
            if (arr[cur] > mx.back().F) {
                while (!mx.empty() && arr[cur] > mx.back().F)
                    mx.pob();
                modify(cur, mx.back().S, arr[cur]);
            }
            mx.eb(arr[cur], cur);
            cur--;
        }
        modify(l, mx.back().S+1, mx.back().F);
        ans[id] = query(l, r+1) - sum(l, r + 1);
    }
    for (int i : ans) cout << i << '\n';
    return 0;
}