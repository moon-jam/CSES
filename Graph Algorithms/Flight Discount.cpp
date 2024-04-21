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

int n, m, a, b, x;
vii g[100005], rg[100005];
int dis[100005], rdis[100005];
bool vis[100005], rvis[100005];

signed main() {
    ios;
    cin >> n >> m;
    rep(i, 1, m) cin >> a >> b >> x, g[a].eb(b, x), rg[b].eb(a, x);
    priority_queue<pii, vii, greater<pii>> pq;
    pq.push({0, 1}), dis[1] = 0;
    rep(i, 2, n) dis[i] = 1e18;
    while (!pq.empty()) {
        pii cur = pq.top();
        pq.pop();
        if (vis[cur.S]) continue;
        vis[cur.S] = 1;
        for (pii i : g[cur.S]) {
            if (cur.F + i.S < dis[i.F]) {
                dis[i.F] = cur.F + i.S;
                pq.push({dis[i.F], i.F});
            }
        }
    }
    pq.push({0, n}), rdis[n] = 0;
    rep(i, 1, n-1) rdis[i] = 1e18;
    while (!pq.empty()) {
        pii cur = pq.top();
        pq.pop();
        if (rvis[cur.S]) continue;
        rvis[cur.S] = 1;
        for (pii i : rg[cur.S]) {
            if (cur.F + i.S < rdis[i.F]) {
                rdis[i.F] = cur.F + i.S;
                pq.push({rdis[i.F], i.F});
            }
        }
    }
    int ans = 1e18;
    rep(i, 1, n) {
        for (pii j : g[i]) tomin(ans, dis[i] + j.S / 2 + rdis[j.F]);
    }
    cout << ans << '\n';
    return 0;
}