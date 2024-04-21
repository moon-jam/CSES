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
vii g[3005];
vi hg[3005], rg[3005];
int dis[3005], cnt[3005];
bool bad = false;
bool vis[3005], rvis[3005];
bool inq[3005];

void dfs(int rt) {
    if (vis[rt]) return;
    vis[rt] = 1;
    for (int i : hg[rt]) dfs(i);
}

void rdfs(int rt) {
    if (rvis[rt]) return;
    rvis[rt] = 1;
    for (int i : rg[rt]) rdfs(i);
}

signed main() {
    ios;
    cin >> n >> m;
    rep(i, 1, m) {
        cin >> a >> b >> x;
        g[a].eb(b, x);
        hg[a].eb(b), rg[b].eb(a);
    }
    dfs(1), rdfs(n);
    queue<int> q;
    rep(i, 1, n) dis[i] = -1e18;
    dis[1] = 0, q.push(1);
    bool bye = false;
    while (!q.empty() && !bye) {
        int cur = q.front();
        q.pop();
        inq[cur] = 0;
        for (auto i : g[cur]) {
            if (dis[i.F] < dis[cur] + i.S) {
                dis[i.F] = dis[cur] + i.S;
                if (!inq[i.F]) inq[i.F] = 1, q.push(i.F);
                cnt[i.F]++;
                if (cnt[i.F] >= n && vis[i.F] && rvis[i.F]) {
                    bad = 1;
                    bye = true;
                    break;
                }
                if (cnt[i.F] >= 2 * n) {
                    bye = 1;
                    break;
                }
            }
        }
    }
    if (bad)
        cout << "-1\n";
    else
        cout << dis[n] << '\n';
    return 0;
}