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

int n, m, deg[100005];
vi g[100005], ans;

void dfs(int rt){
    while(!g[rt].empty()){
        int cur = g[rt].back();
        g[rt].pob();
        dfs(cur);
    }
    ans.eb(rt);
}

signed main() {
    ios;
    cin >> n >> m;
    rep(i, 1, m){
        int a, b;
        cin >> a >> b;
        g[a].eb(b);
        deg[a]++, deg[b]++;
    }
    rep(i, 1+1, n-1) if(deg[i]&1){
        cout << "IMPOSSIBLE\n";
        return 0;
    } 
    if(!((deg[1]&1) && (deg[n]&1))){
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    dfs(1);
    rep(i, 1, n) if(!g[i].empty()){
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    reverse(all(ans));
    for(int i : ans) cout << i << ' ';
    return 0;
}