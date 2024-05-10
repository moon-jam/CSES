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
int par[200005][20];
int in[200005], out[200005];
vi g[200005];

void dfs(int rt, int &time) {
    in[rt] = time++;
    for (int i = 1; par[rt][i] != -1 && par[par[rt][i]][i] != -1; i++) par[rt][i + 1] = par[par[rt][i]][i];
    for (int i : g[rt]) {
        par[i][1] = rt;
        dfs(i, time);
    }
    out[rt] = time++;
}

signed main() {
    ios;
    memset(par, -1, sizeof(par));
    cin >> n >> q;
    rep(i, 2, n) {
        int x;
        cin >> x;
        g[x].eb(i);
    }
    dfs(1, *(new int(0)));
    while (q--) {
        int a, b;
        cin >> a >> b;
        if((in[a] <= in[b]) && (out[b] <= out[a])) {
            cout << a << '\n';
            continue;
        } else if((in[b] < in[a]) && (out[a] < out[b])) {
            cout << b << '\n';
            continue;
        }
        rev(i, 19, 1) {
            if (par[a][i] == -1) continue;
            if (in[par[a][i]] < in[b] && out[b] < out[par[a][i]]) continue;
            a = par[a][i];
        }
        cout << par[a][1] << '\n';
    }
    return 0;
}