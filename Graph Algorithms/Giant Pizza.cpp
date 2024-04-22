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

#define n(a) ((a + m) % (2 * m) == 0 ? 2 * m : (a + m) % (2 * m))

int n, m, id = 0;
vi g[200005], rg[200005], ord;
int idx[200005];
bool vis[200005], rvis[200005];

void dfs(int rt) {
    if (vis[rt]) return;
    vis[rt] = 1;
    for (int i : g[rt]) dfs(i);
    ord.eb(rt);
}

void rdfs(int rt) {
    if (rvis[rt]) return;
    rvis[rt] = 1;
    idx[rt] = id;
    for (int i : rg[rt]) rdfs(i);
}

signed main() {
    ios;
    cin >> n >> m;
    rep(i, 1, n) {
        int a, b;
        char aa, bb;
        cin >> aa >> a >> bb >> b;
        if (aa == '-') a = n(a);
        if (bb == '-') b = n(b);
        g[n(a)].eb(b);
        g[n(b)].eb(a);
        rg[b].eb(n(a));
        rg[a].eb(n(b));
    }
    rep(i, 1, m * 2) dfs(i);
    reverse(all(ord));
    for (int i : ord)
        if (!rvis[i]) id++, rdfs(i);
    rep(i, 1, m * 2) 
        if (idx[i] == idx[n(i)]) {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
    rep(i, 1, m) 
        if(idx[i]>idx[n(i)]) cout << "+ ";
        else cout << "- ";
    return 0;
}
