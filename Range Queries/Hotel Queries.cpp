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

int seg[200005 * 4];

void modify(int pos, int val, int L, int R, int id) {
    if (L == R - 1)
        seg[id] += val;
    else {
        if (pos >= M)
            modify(pos, val, M, R, rc);
        else
            modify(pos, val, L, M, lc);
        seg[id] = max(seg[lc], seg[rc]);
    }
}

int query(int l, int r, int L, int R, int id) {
    if (l == L && r == R) return seg[id];
    if (l >= M) return query(l, r, M, R, rc);
    if (r <= M) return query(l, r, L, M, lc);
    return max(query(l, M, L, M, lc), query(M, r, M, R, rc));
}

signed main() {
    // ios;
    int n, m, tmp;
    cin >> n >> m;
    set<pii> h;
    rep(i, 0, n - 1) cin >> tmp, modify(i, tmp, 0, n, 0);
    rep(i, 1, m) {
        cin >> tmp;
        if (query(0, n, 0, n, 0) < tmp) {
            cout << 0 << ' ';
            continue;
        }
        int l = 1, r = n;
        while (r > l) {
            int mid = (r + l) / 2;
            if (query(0, mid, 0, n, 0) >= tmp)
                r = mid;
            else
                l = mid+1;
        }cout << r << ' ';
        modify(r-1, -tmp, 0, n, 0);
    }
    return 0;
}