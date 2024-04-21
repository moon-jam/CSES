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

int mod = 1e9+7;

vi g[100005];
int deg[100005];
int n, m;
int way[100005];
bool vis[100005];

void dfs(int rt){
    if(vis[rt]) return;
    vis[rt] = 1;
    for(int i : g[rt]){
        deg[i]++;
        dfs(i);
    }
}

signed main() {
    ios;
    cin >> n >> m;
    rep(i, 1, m){
        int a, b;
        cin >> a >> b;
        g[a].eb(b);
    }
    dfs(1);
    way[1] = 1;
    vi v;
    v.eb(1);
    while(!v.empty()){
        int cur = v.back();
        v.pob();
        for(int i : g[cur]){
            way[i] += way[cur] %= mod;
            deg[i]--;
            if(deg[i] == 0) v.eb(i);
        }
    }
    cout << way[n] % mod << '\n';
    return 0;
}