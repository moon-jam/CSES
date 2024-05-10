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

int n, m;
int in[200005], out[200005], par[200005][20], path[200005], path_from_ch[200005];
vi g[200005];

void dfs(int rt, int pa, int &time){
    for(int i = 0; par[rt][i]!=-1 && par[par[rt][i]][i]!=-1; i++) par[rt][i+1] = par[par[rt][i]][i];
    in[rt] = time++;
    for(int i : g[rt]) if(pa!=i) par[i][0] = rt, dfs(i, rt, time);
    out[rt] = time++; 
}

void dfs_cnt_path(int rt, int pa){
    for(int i : g[rt]) if(i!=pa) dfs_cnt_path(i,rt),path[rt]+=path[i]-path_from_ch[i];
    path[rt]-=path_from_ch[rt];
}

signed main() {
    ios;
    memset(par, -1, sizeof(par));
    cin >> n >> m;
    rep(i, 2, n){
        int a, b;
        cin >> a >> b;
        g[a].eb(b), g[b].eb(a);
    }
    dfs(1, -1, *(new int(0)));
    while(m--){
        int a, b, lca;
        cin >> a >> b;
        if(in[a]<=in[b] && out[b]<=out[a]) lca = a;
        else if(in[b]<=in[a] && out[a]<=out[b]) lca = b;
        else {
            lca = a;
            rev(i, 19, 0){
                if(par[lca][i] == -1) continue;
                if(in[par[lca][i]]<in[b] && out[b]<out[par[lca][i]]) continue;
                lca = par[lca][i];
            }
            lca = par[lca][0];
        }
        path[a]++, path[b]++;
        // cout << lca << '\n';
        path_from_ch[lca]++;
    }
    dfs_cnt_path(1, 0);
    rep(i, 1, n) cout << path[i] << ' ';
    return 0;
}