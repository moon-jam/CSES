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
vi g[100005];
int deg[100005];
int dis[100005];
int last[100005];
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
    if(!vis[n]){
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    vi st;
    st.eb(1);
    while(!st.empty()){
        int cur = st.back();
        st.pob();
        for(int i : g[cur]){
            deg[i]--;
            if(dis[i] < dis[cur]+1){
                dis[i] = dis[cur]+1;
                last[i] = cur;
            }
            if(deg[i]==0) st.eb(i);
        }
    }
    cout << dis[n]+1 << '\n';
    vi ans;
    for(int i = n; i!=0; i=last[i]){
        ans.eb(i);
    }
    reverse(all(ans));
    for(int i : ans) cout << i << ' ';
    return 0;
}