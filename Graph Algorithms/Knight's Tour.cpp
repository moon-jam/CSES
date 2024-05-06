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

int x, y;
int dir[8][2] = {{1, 2}, {2, 1}, {1, -2}, {-2, 1}, {-1, 2}, {2, -1}, {-1, -2}, {-2, -1}};
bool vis[10][10];
vii ans;
int out[10][10];

bool dfs(int x, int y, int cnt) {
    if (vis[x][y]) return 0;
    if (cnt == 63) {
        ans.eb(x, y);
        return 1;
    }
    vis[x][y] = 1;
    cnt++;
    vector<pair<int, pii>> go;
    rep(i, 0, 7) {
        if (x + dir[i][0] > 8 || x + dir[i][0] < 1 || y + dir[i][1] > 8 || y + dir[i][1] < 1) continue;
        int nx = x + dir[i][0], ny = y + dir[i][1], deg = 0;
        rep(i, 0, 7) if (!(nx + dir[i][0] > 8 || nx + dir[i][0] < 1 || ny + dir[i][1] > 8 || ny + dir[i][1] < 1)) deg++;
        go.pb({deg, {nx, ny}});
    }
    sort(all(go));
    for (auto i : go)
        if (dfs(i.S.F, i.S.S, cnt)) {
            ans.eb(x,y);
            return 1;
        }
    vis[x][y] = 0;
    return 0;
}

signed main() {
    ios;
    cin >> x >> y;
    dfs(x, y, 0);
    reverse(all(ans));
    rep(i, 1, 64) { out[ans[i - 1].F][ans[i - 1].S] = i;}
    rep(i, 1, 8) {
        rep(j, 1, 8) cout << out[j][i] << ' ';
        cout << '\n';
    }
    return 0;
}