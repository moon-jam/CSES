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

int n, q;
int par[200005][20];
vi g[200005];

void dfs(int rt){
    for(int i = 1; par[rt][i] != -1 && par[par[rt][i]][i]!=-1; i++) par[rt][i+1] = par[par[rt][i]][i];
    for(int i : g[rt]){
        par[i][1] = rt;
        dfs(i);
    }
}

signed main() {
    ios;
    memset(par, -1, sizeof(par));
    cin >> n >> q;
    rep(i, 2, n){
        int x;
        cin >> x;
        g[x].eb(i);
    }
    dfs(1);
    while(q--) {
        int x, k;
        cin >> x >> k;
        for(int i = 1, j = 1; i <= k && x!=-1; i<<=1, j++){
            if(i&k) x = par[x][j];
        }
        cout << x << '\n';
    }
    return 0;
}