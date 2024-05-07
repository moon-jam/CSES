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

int n;
vi g[200005];
int in[200005], out[200005], tree_size[200005];  // ans[i] = in[i]+out[i]
// in[i] = ∑ (in[j] + subtree_size[j]), j = each i's child
// out[i] = (out[par]+(n-subtree_size[par]+1)) + ∑ (in(j) + subtree_size[j]*2), j = i's sibling

void dfs(int rt, int par) {
    tree_size[rt] = 1;
    for (int i : g[rt]) {
        if (i == par) continue;
        dfs(i, rt);
        tree_size[rt] += tree_size[i];
        in[rt] += in[i] + tree_size[i];
    }
}

void dfs2(int rt, int par, int tmp) {
    out[rt] = out[par] + (n - tree_size[par] + 1) + (tmp - in[rt] - tree_size[rt] * 2);
    tmp = 0;
    for (int i : g[rt])
        if (i != par) tmp += in[i] + tree_size[i] * 2;
    for (int i : g[rt])
        if (i != par) dfs2(i, rt, tmp);
}

signed main() {
    ios;
    cin >> n;
    rep(i, 1, n - 1) {
        int a, b;
        cin >> a >> b;
        g[a].eb(b), g[b].eb(a);
    }
    tree_size[0] = n + 1;
    dfs(1, 0), dfs2(1, 0, in[1] + tree_size[1] * 2);
    rep(i, 1, n) cout << in[i] + out[i] << ' ';
    return 0;
}