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

int n, m, min_l = INT_MAX, min_ls, min_le;
vi E[100005];
int lev[100005], parent[100005];
bool vis[100005];

void dfs(int u) {
    if (vis[u]) return;
    vis[u] = 1;
    for (int i : E[u]) {
        if (!vis[i])
            lev[i] = lev[u] + 1, parent[i] = u, dfs(i);
        else if(lev[u] > lev[i] && i != parent[u]){
            int path = lev[u] - lev[i] + 2;
            if (path < min_l) min_l=path, min_ls = u, min_le = i;
        }
    }
}

signed main() {
    ios;
    int tmp1, tmp2;
    memset(vis, 0, sizeof(vis));
    memset(lev, 0, sizeof(lev));
    cin >> n >> m;
    rep(i, 1, m) cin >> tmp1 >> tmp2, E[tmp1].eb(tmp2), E[tmp2].eb(tmp1);
    rep(i, 1, n) dfs(i);
    if(min_l == INT_MAX) cout << "IMPOSSIBLE\n";
    else{
        cout << min_l << '\n';
        tmp1 = min_ls;
        rep(i, 2, min_l){
            cout << min_ls << ' ';
            min_ls = parent[min_ls];
        }cout << tmp1 << '\n';
    }
    return 0;
}