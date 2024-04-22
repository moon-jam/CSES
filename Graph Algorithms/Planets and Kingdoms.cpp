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

int id = 0;
int n, m;
vi g[100005], rg[100005], ord;
int idx[100005];
bool vis[100005], rvis[100005];

void dfs(int rt){
    if(vis[rt]) return;
    vis[rt] = 1;
    for(int i : g[rt]) dfs(i);
    ord.eb(rt);
}

void rdfs(int rt){
    if(rvis[rt]) return;
    rvis[rt] = 1;
    for(int i : rg[rt]) rdfs(i);
    idx[rt] = id;
}

signed main() {
    ios;
    cin >> n >> m;
    rep(i, 1, m) {
        int a, b;
        cin >> a >> b;
        g[a].eb(b);
        rg[b].eb(a);
    }
    rep(i, 1, n) dfs(i);
    reverse(all(ord));
    for(int i : ord) if(!rvis[i]) id++,rdfs(i);
    cout << id << '\n';
    rep(i, 1, n) cout << idx[i] << ' ';
    return 0;
}