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

int n, q, s;

struct Q {
    int l, r, id, ans;
    bool operator<(const Q &b) const {
        if (l / s != b.l / s) return l < b.l;
        return ((l / s) & 1) ? (r < b.r) : (r > b.r);
    }
};

signed main() {
    ios;
    cin >> n >> q;
    vi arr(n + 1);
    vi ord;
    rep(i, 1, n) cin >> arr[i], ord.eb(arr[i]);
    sort(all(ord));
    rep(i, 1, n) arr[i] = (lower_bound(all(ord), arr[i])-ord.begin());
    s = sqrt(n);
    
    vii in(q);
    vector<Q> queries(q);
    
    for(pii &i : in) cin >>i.F >> i.S;
    
    rep(i, 0, q - 1) queries[i] = {in[i].F, in[i].S, i, 0};
    sort(all(queries));

    int cur_l = 1, cur_r = 1;
    vi cnt(n+1, 0);
    cnt[arr[1]] = 1;
    int distinct = 1;

    for (auto &query : queries) {
        while (cur_l > query.l) {
            cur_l--;
            if (++cnt[arr[cur_l]] == 1) distinct++;
        }
        while (cur_r < query.r) {
            cur_r++;
            if (++cnt[arr[cur_r]] == 1) distinct++;
        }
        while (cur_l < query.l) {
            if (--cnt[arr[cur_l]] == 0) distinct--;
            cur_l++;
        }
        while (cur_r > query.r) {
            if (--cnt[arr[cur_r]] == 0) distinct--;
            cur_r--;
        }
        query.ans = distinct;
    }

    vi ans(q);
    for (auto &query : queries) ans[query.id] = query.ans;
    for (auto &x : ans) cout << x << '\n';
    return 0;
}