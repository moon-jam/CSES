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

int bit[400005];
int n;

void modify(int pos, int val) {
    for (; pos <= 2 * n+1; pos += (pos & -pos))
        tomax(bit[pos], val);
}

int query(int pos) {
    int ans = 0;
    for (; pos > 0; pos -= (pos & -pos)) tomax(ans, bit[pos]);
    return ans;
}

signed main() {
    ios;
    cin >> n;
    vector<pair<pii, int>> p(n);
    vi ord;
    for (auto &i : p)
        cin >> i.F.F >> i.F.S >> i.S, ord.eb(i.F.F), ord.eb(i.F.S);
    sort(all(p));
    sort(all(ord));
    for (auto &i : p) {
        i.F.F = (int)(lower_bound(all(ord), i.F.F) - ord.begin())+1;
        i.F.S = (int)(lower_bound(all(ord), i.F.S) - ord.begin())+1;
        modify(i.F.S, query(i.F.F - 1) + i.S);
        // err(i.F.F sp i.F.S sp query(i.F.F - 1) sp query(i.F.S));
    }
    cout << query(2 * n+1) << '\n';
    return 0;
}