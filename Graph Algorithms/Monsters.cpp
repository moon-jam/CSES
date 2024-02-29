#include <bits/stdc++.h>
using namespace std;
/* TYPES  */
// #define int long long
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

bool vis[1003][1003];
bool vis_h[1003][1003];

signed main() {
    ios;
    int n, m;
    char g[1003][1003];
    cin >> n >> m;
    queue<pair<pii, bool> > pt;
    int from[1003][1003];
    bool ok = 0;
    pair<pii, bool> a;
    pii de;
    int dir_x[5] = {1, 0, -1, 0}, dir_y[5] = {0, 1, 0, -1};
    char dir[5] = {'D', 'R', 'U', 'L'};

    rep(i, 0, n - 1) rep(j, 0, m - 1) {
        cin >> g[i][j];
        if (g[i][j] == '#') vis[i][j] = 1;
        if (g[i][j] == 'M') pt.push({{i, j}, 0}), vis[i][j] = 1;
        if (g[i][j] == 'A') a = {{i, j}, 1}, vis_h[i][j] = 1;
    }
    pt.push(a);
    while (!pt.empty()) {
        // 0 U, 1 R, 2 D, 3 L
        auto x = pt.front();
        pt.pop();
        // cout << x.F.F sp x.F.S << '\n';
        if (!x.S) {
            rep(i, 0, 3) {
                int xx = x.F.F + dir_x[i], yy = x.F.S + dir_y[i];
                if (!vis[xx][yy] && xx >= 0 && xx <= n - 1 && yy >= 0 &&
                    yy <= m - 1) {
                    pt.push({{xx, yy}, 0});
                    vis[xx][yy] = 1;
                }
            }
        } else if (x.S && (x.F.F == 0 || x.F.S == 0 || x.F.F == n - 1 ||
                           x.F.S == m - 1)) {
            // cout << x.F.F sp x.F.S << '\n';
            ok = 1;
            de = {x.F.F, x.F.S};
            break;
        } else if (x.S) {
            // cout << x.F.F sp x.F.S << '\n';
            // cout << '\n';
            rep(i, 0, 3) {
                if (!vis[x.F.F + dir_x[i]][x.F.S + dir_y[i]] &&
                    !vis_h[x.F.F + dir_x[i]][x.F.S + dir_y[i]]) {
                    pt.push({{x.F.F + dir_x[i], x.F.S + dir_y[i]}, 1});
                    vis_h[x.F.F + dir_x[i]][x.F.S + dir_y[i]] = 1;
                    from[x.F.F + dir_x[i]][x.F.S + dir_y[i]] = i;
                }
            }
        }
    }
    if (!ok)
        cout << "NO\n";
    else {
        cout << "YES\n";
        vector<char> ans;
        while (de.F != a.F.F || de.S != a.F.S) {
            // cout << de.F sp de.S << '\n';
            int tmpF = de.F;
            ans.eb(dir[from[de.F][de.S]]);
            de.F -= dir_x[from[de.F][de.S]];
            de.S -= dir_y[from[tmpF][de.S]];
            // cout << de.F sp de.S << "\n\n";
        }
        cout << ans.size() << '\n';
        reverse(all(ans));
        for (char i : ans) cout << i;
    }
    return 0;
}