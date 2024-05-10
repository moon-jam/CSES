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

int n, q;
int in[200005], out[200005], par[200005][20];
vi g[200005];

void dfs(int rt, int pa, int &time) {
    in[rt] = time++;
    par[rt][0] = pa;
    for (int i = 0; rt!=1 && par[par[rt][i]][i] != -1; i++) par[rt][i + 1] = par[par[rt][i]][i];
    for (int i : g[rt]) {
        if (pa != i) dfs(i, rt, time);
    }
    out[rt] = time++;
}

int dis(int ch, int ac, int from) {
    if (ch == ac) return 0;
    while (par[ch][from] == -1) from--;
    while (from >= 0 && in[par[ch][from]] < in[ac]) from--;
    return (1 << from) + dis(par[ch][from], ac, from);
}

signed main() {
    ios;
    memset(par, -1, sizeof(par));
    cin >> n >> q;
    rep(i, 1, n - 1) {
        int a, b;
        cin >> a >> b;
        g[a].eb(b), g[b].eb(a);
    }
    dfs(1, -1, *(new int(0)));
    while (q--) {
        int a, b;
        cin >> a >> b;
        if (in[a] > in[b]) swap(a, b);
        int lca;
        if (out[b] <= out[a])
            lca = a;
        else {
            lca = a;
            rev(i, 19, 0) {
                if (par[lca][i] == -1) continue;
                if (in[par[lca][i]] < in[b] && out[b] < out[par[lca][i]]) continue;
                lca = par[lca][i];
            }
            lca = par[lca][0];
        }
        cout << dis(a, lca, 19) + dis(b, lca, 19) << '\n';
    }
    return 0;
}