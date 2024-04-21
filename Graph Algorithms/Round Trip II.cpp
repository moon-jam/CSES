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

int n, m, a, b;
vi g[100005];
vi ans;
bool vis[100005];
bool cur_vis[100005];

int dfs(int rt) {
    if (cur_vis[rt] || !ans.empty()) return 0;
    vis[rt] = cur_vis[rt] = 1;
    for (int i : g[rt]) {
        if (cur_vis[i]) {
            ans.eb(i), ans.eb(rt);
            return i;
        } else if(!vis[i]) { // 若是vis[i]，則代表以i作為其中一點，一定不會形成環
            int flag = dfs(i);
            if (!flag && !ans.empty()) return 0;
            if (!flag) continue;
            ans.eb(rt);
            if (flag == rt) return 0;
            return flag;
        }
    }
    cur_vis[rt] = 0;
    return 0;
}

signed main() {
    ios;
    cin >> n >> m;
    rep(i, 1, m) cin >> a >> b, g[a].eb(b);
    rep(i, 1, n) if (!vis[i] && ans.empty()) dfs(i);
    if (ans.empty())
        cout << "IMPOSSIBLE";
    else {
        cout << ans.size() << '\n';
        reverse(all(ans));
        for (int i : ans) cout << i << ' ';
    }
    return 0;
}