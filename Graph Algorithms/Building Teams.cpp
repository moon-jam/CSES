#include <bits/stdc++.h>
using namespace std;
/* TYPES  */
#define int long long
#define pii pair<int, int>
#define F first
#define S second
#define vi vector<int>
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
#define sp << " " <<
#define ios ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

vi E[100005];
vi team;
int n, m, tmp1, tmp2;
bool build_team = true;

void dfs(int r) {
    int draw = team[r] % 2 + 1;
    for (int i : E[r]) {
        if (team[i] == 0)
            team[i] = draw, dfs(i);
        else if (team[i] == draw)
            continue;
        else {
            build_team = false;
            return;
        }
    }
}

signed main() {
    ios;
    // bipartite graph
    cin >> n >> m;
    team.resize(n + 1), team.assign(n + 1, 0);
    rep(i, 1, m) {
        cin >> tmp1 >> tmp2;
        E[tmp1].eb(tmp2), E[tmp2].eb(tmp1);
    }
    rep(i, 1, n) {
        if (team[i] == 0) team[i] = 1, dfs(i);
    }
    if (build_team) {
        team.erase(team.begin());
        for (int i : team) cout << i << ' ';
    } else
        cout << "IMPOSSIBLE";
    return 0;
}