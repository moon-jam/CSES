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

signed main() {
    ios;
    int n, room = 0;
    cin >> n;
    vi ans(n);
    vector<pair<pii, int>> d(n);
    rep(i, 0, n - 1) cin >> d[i].F.F >> d[i].F.S, d[i].S = i;
    sort(all(d));
    priority_queue<pii, vii, greater<pii>> pq;
    for (auto i : d) {
        if (!pq.empty() && pq.top().F < i.F.F) {
            ans[i.S] = pq.top().S;
            pq.pop();
            pq.push({i.F.S, ans[i.S]});
        } else {
            ++room;
            pq.push({i.F.S, room});
            ans[i.S] = room;
        }
    }
    cout << room << '\n';
    for(int i : ans) cout << i << ' ';
    return 0;
}