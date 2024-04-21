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

int n, m, edge = 0, cost = 0;
int boss[200005];
vector<tuple<int, int, int>> g, tg;

int find_boss(int ch){
    if(ch == boss[ch]) return ch;
    return boss[ch] = find_boss(boss[ch]);
}

signed main() {
    ios;
    cin >> n >> m;
    g.resize(m);
    rep(i, 1, n) boss[i] = i;
    for(auto &[w, u, v] : g) cin >> u >> v >> w;
    sort(all(g));
    for(auto [w, u, v] : g){
        if(find_boss(u) == find_boss(v)) continue;
        boss[find_boss(u)] = boss[find_boss(v)];
        cost += w;
        edge++;
    }
    if(edge != n-1) cout << "IMPOSSIBLE\n";
    else cout << cost << '\n';
    return 0;
}