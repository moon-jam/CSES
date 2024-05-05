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

int n, m, st=1, ed=1, cnt_odd = 0;
si g[100005];
vi ans;

void dfs(int rt){
    while(!g[rt].empty()){
        int cur = *g[rt].begin();
        g[rt].erase(g[rt].begin());
        g[cur].erase(rt);
        dfs(cur);
    }
    ans.eb(rt);
}

signed main() {
    ios;
    cin >> n >> m;
    si cg;
    rep(i, 1, m){
        int a, b;
        cin >> a >> b;
        g[a].insert(b), g[b].insert(a);
    }
    rep(i, 1, n) if(g[i].size()&1) ed = st, st = i, cnt_odd++;
    if(cnt_odd!=0) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    dfs(st);
    rep(i, 1, n) if(!g[i].empty()) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    reverse(all(ans));
    for(int i : ans) cout << i << ' ';
    return 0;
}