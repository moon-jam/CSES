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

int n, m, a, b, x;
vector<pair<pii, int>> g;
vi hg[3005], rg[3005];
int dis[3005];
bool bad = false;
bool vis[3005], rvis[3005];

void dfs(int rt){
    if(vis[rt]) return;
    vis[rt] = 1;
    for(int i : hg[rt]) dfs(i);
}

void rdfs(int rt){
    if(rvis[rt]) return;
    rvis[rt] = 1;
    for(int i : rg[rt]) rdfs(i);
}

signed main() {
    ios;
    cin >> n >> m;
    rep(i, 1, m) {
        cin >> a >> b >> x;
        g.pb({{a, b}, x});
        hg[a].eb(b), rg[b].eb(a);
    }
    dfs(1), rdfs(n);
    dis[1] = 0;
    rep(i, 2, n) dis[i] = -1e18;
    rep(j, 1, n) {
        for (auto i : g) {
            if (dis[i.F.S] < dis[i.F.F] + i.S) {
                dis[i.F.S] = dis[i.F.F] + i.S;
                if (j == n && vis[i.F.S] && rvis[i.F.S]) bad = 1;
            }
        }
    }
    if (bad)
        cout << "-1\n";
    else
        cout << dis[n] << '\n';
    return 0;
}