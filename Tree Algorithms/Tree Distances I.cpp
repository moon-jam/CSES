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

int n, ans[200005];
vi g[200005];

int bfs(int rt){
    vi dis(n+1, -1);
    queue<int> q;
    q.push(rt);
    dis[rt] = 0;
    while(!q.empty()){
        rt = q.front();
        q.pop();
        for(int i : g[rt]){
            if(~dis[i]) continue;
            q.push(i), dis[i]=dis[rt]+1, tomax(ans[i], dis[i]);
        }
    }
    return rt;
}

signed main() {
    ios;
    cin >> n;
    rep(i, 1, n-1){
        int a, b;
        cin >> a >> b;
        g[a].eb(b), g[b].eb(a);
    }
    bfs(bfs(bfs(1))); // find endpoint1, update ans from endpoint1 & find endpoint 2, update ans from endpoint2
    rep(i, 1, n) cout << ans[i] << ' ';
    return 0;
}