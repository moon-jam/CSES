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
int arr[200005];
 
void pull(int id) { seg[id] = seg[lc] + seg[rc]; }
 
void modify(int pos, int val, int L, int R, int id) {
    if (L == R - 1) {
        seg[id] = val;
        return;
    }
    if (pos >= M)
        modify(pos, val, M, R, rc);
    else
        modify(pos, val, L, M, lc);
    pull(id);
}
 
int query(int l, int r, int L, int R, int id) {
    if (l == L && r == R) return seg[id];
    if (l >= M) return query(l, r, M, R, rc);
    if (r <= M) return query(l, r, L, M, lc);
    return query(l, M, L, M, lc) + query(M, r, M, R, rc);
}
 
signed main() {
    ios;
    int n, q;
    cin >> n >> q;
    rep(i, 0, n - 1) cin >> arr[i], modify(i, arr[i], 0, n, 0);
    while (q--) {
        int cmd, a, b;
        cin >> cmd >> a >> b;
        a--;
        if (cmd == 1)
            modify(a, b, 0, n, 0);
        else
            cout << query(a, b, 0, n, 0) << '\n';
    }
    return 0;
}
