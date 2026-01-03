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

// Small-To-Large Merging

int n, ans[200005], c[200005];
vi g[200005];

si dfs(int rt, int par){
    si res{c[rt]};
    for(int i : g[rt]){
        if(i == par) continue;
        si ch = dfs(i, rt);
        if(ch.size() > res.size()) swap(res, ch);
        res.merge(ch);
    }
    ans[rt] = res.size();
    return res;
}

signed main() {
    ios;
    cin >> n;
    rep(i, 1, n) cin >> c[i];
    rep(i, 1, n-1){
        int a, b;
        cin >> a >> b;
        g[a].eb(b), g[b].eb(a);
    }
    dfs(1, 0);
    rep(i, 1, n) cout << ans[i] << ' ';
    return 0;
}