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

#define lc id * 2 + 1
#define rc id * 2 + 2
#define mid ((l + r) / 2)

int n, q, w[200005];
int seg[800005], dep[200005], par[200005], in[200005], boss[200005], sz[200005], h_child[200005];
vi g[200005];

void modify(int pos, int val, int l = 0, int r = n, int id = 0) {
    if (r - l == 1) {seg[id] = val; return;}
    if (pos >= mid)
        modify(pos, val, mid, r, rc);
    else
        modify(pos, val, l, mid, lc);
    seg[id] = max(seg[lc], seg[rc]);
}

int query(int L, int R, int l = 0, int r = n, int id = 0) {
    if (L == l && R == r) return seg[id];
    if (L >= mid) return query(L, R, mid, r, rc);
    if (R <= mid) return query(L, R, l, mid, lc);
    return max(query(L, mid, l, mid, lc), query(mid, R, mid, r, rc));
}

void dfs_pre(int rt, int pa) {
    dep[rt] = dep[pa] + 1;
    par[rt] = pa;
    sz[rt] = 1;
    int h_ch = -1, h_sz = -1;
    for (int i : g[rt]) {
        if (pa == i) continue;
        dfs_pre(i, rt);
        sz[rt] += sz[i];
        if(sz[i] > h_sz) h_sz=sz[i], h_ch=i;
    }
    h_child[rt] = h_ch;
}

void dfs_hld(int rt, int pa, int bos, int &time){
    modify(time, w[rt]);
    in[rt] = time++;
    boss[rt] = bos;
    if(h_child[rt] == -1) return;
    dfs_hld(h_child[rt], rt, bos, time);
    for(int i : g[rt]) if(i!=pa && i!=h_child[rt]) dfs_hld(i, rt, i, time);
}

int ask(int a, int b){
    int ans = 0;
    while(boss[a] != boss[b]) {
        if(dep[boss[a]] < dep[boss[b]]) swap(a, b);
        tomax(ans, query(in[boss[a]], in[a]+1));
        a = par[boss[a]];
    }
    if(dep[a]>dep[b]) swap(a, b);
    tomax(ans, query(in[a], in[b]+1));
    return ans;
}

signed main() {
    ios;
    cin >> n >> q;
    rep(i, 1, n) cin >> w[i];
    rep(i, 1, n-1){
        int a, b;
        cin >> a >> b;
        g[a].eb(b), g[b].eb(a);
    }
    dfs_pre(1, 1), dfs_hld(1,1,1, *(new int(0)));
    while(q--){
        int cmd, a, b;
        cin >> cmd >> a >> b;
        if(cmd == 1) modify(in[a], b);
        else cout << ask(a, b) << ' ';
    }
    return 0;
}