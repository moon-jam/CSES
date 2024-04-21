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

int n, m, k, a, b, w;
vi dis[100005];
vii g[100005];

signed main() {
    ios;
    cin >> n >> m >> k;
    rep(i, 1, m) cin >> a >> b >> w, g[a].eb(b, w);
    priority_queue<pii, vii, greater<pii> > pq;
    pq.push({0, 1});
    while (!pq.empty()) {
        pii cur = pq.top();
        pq.pop();
        if (dis[cur.S].size() >= k) continue;
        dis[cur.S].eb(cur.F);
        for (pii i : g[cur.S]) pq.push({cur.F + i.S, i.F});
    }
    for (int i : dis[n]) cout << i << ' ';
    return 0;
}