# Tree Algorithms

## Subordinates

```c++ Subordinates
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

int n;
int tree_size[200005];
vi g[200005];

int dfs(int rt){
    if(tree_size[rt]) return tree_size[rt];
    tree_size[rt] = 1;
    for(int i : g[rt]) tree_size[rt] += dfs(i);
    return tree_size[rt];
}

signed main() {
    ios;
    cin >> n;
    rep(i, 2, n) {
        int tmp;
        cin >> tmp;
        g[tmp].eb(i);
    }
    dfs(1);
    rep(i, 1, n) cout << tree_size[i]-1 << ' ';
    return 0;
}
```

## Tree Matching

```c++ Tree Matching
#include <bits/stdc++.h>
using namespace std;
/* TYPES  */
#define int long long
#define pii match<int, int>
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

int n, ans;
vi g[200005];
bool match[200005];
//假設子孫的樹已經是最佳答案（最大配對），那讓眾多子孫選擇是否與父母一對，因為父母一定只能成全一對子孫，所以不管選誰都不會影響答案，所以在父母這層答案是最大

void dfs(int rt, int par){
    for(int i : g[rt]){
        if(i==par) continue;
        dfs(i, rt);
        if(!match[rt] && !match[i]) match[rt]=match[i]=1, ans++;
    }
}

signed main() {
    ios;
    cin >> n;
    
    rep(i, 2, n){
        int a, b;
        cin >> a >> b;
        g[a].eb(b), g[b].eb(a);
    }
    dfs(1, 0);
    cout << ans << '\n';
    return 0;
}
```

## Tree Diameter

```c++ Tree Diameter
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

int n, ans;
int d1[200005], d2[200005];
vi g[200005];

void dfs(int rt, int par){
    d1[rt] = 1, d2[rt] = 0;
    for(int i : g[rt]){
        if(i == par) continue;
        dfs(i, rt);
        if(d1[i]+1 > d1[rt]) d2[rt] = d1[rt], d1[rt]=d1[i]+1;
        else if(d1[i]+1 >= d2[rt]) d2[rt]=d1[i]+1;
    }
}

signed main() {
    ios;
    cin >> n;
    rep(i, 2, n){
        int a, b;
        cin >> a >> b;
        g[a].eb(b);
        g[b].eb(a);
    }
    dfs(1, 0);
    cout << d1[1]+d2[1]-2 << '\n';
    return 0;
}
```

## Tree Distances I

```c++ Tree Distances I
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
```

## Tree Distances II

```c++ Tree Distances II
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

int n;
vi g[200005];
int in[200005], out[200005], tree_size[200005];  // ans[i] = in[i]+out[i]
// in[i] = ∑ (in[j] + subtree_size[j]), j = each i's child
// out[i] = (out[par]+(n-subtree_size[par]+1)) + ∑ (in(j) + subtree_size[j]*2), j = i's sibling

void dfs(int rt, int par) {
    tree_size[rt] = 1;
    for (int i : g[rt]) {
        if (i == par) continue;
        dfs(i, rt);
        tree_size[rt] += tree_size[i];
        in[rt] += in[i] + tree_size[i];
    }
}

void dfs2(int rt, int par, int tmp) {
    out[rt] = out[par] + (n - tree_size[par] + 1) + (tmp - in[rt] - tree_size[rt] * 2);
    tmp = 0;
    for (int i : g[rt])
        if (i != par) tmp += in[i] + tree_size[i] * 2;
    for (int i : g[rt])
        if (i != par) dfs2(i, rt, tmp);
}

signed main() {
    ios;
    cin >> n;
    rep(i, 1, n - 1) {
        int a, b;
        cin >> a >> b;
        g[a].eb(b), g[b].eb(a);
    }
    tree_size[0] = n + 1;
    dfs(1, 0), dfs2(1, 0, in[1] + tree_size[1] * 2);
    rep(i, 1, n) cout << in[i] + out[i] << ' ';
    return 0;
}
```

## Company Queries I

```c++ Company Queries I
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
```

## Company Queries II

```c++ Company Queries II
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
int in[200005], out[200005];
vi g[200005];

void dfs(int rt, int &time) {
    in[rt] = time++;
    for (int i = 1; par[rt][i] != -1 && par[par[rt][i]][i] != -1; i++) par[rt][i + 1] = par[par[rt][i]][i];
    for (int i : g[rt]) {
        par[i][1] = rt;
        dfs(i, time);
    }
    out[rt] = time++;
}

signed main() {
    ios;
    memset(par, -1, sizeof(par));
    cin >> n >> q;
    rep(i, 2, n) {
        int x;
        cin >> x;
        g[x].eb(i);
    }
    dfs(1, *(new int(0)));
    while (q--) {
        int a, b;
        cin >> a >> b;
        if((in[a] <= in[b]) && (out[b] <= out[a])) {
            cout << a << '\n';
            continue;
        } else if((in[b] < in[a]) && (out[a] < out[b])) {
            cout << b << '\n';
            continue;
        }
        rev(i, 19, 1) {
            if (par[a][i] == -1) continue;
            if (in[par[a][i]] < in[b] && out[b] < out[par[a][i]]) continue;
            a = par[a][i];
        }
        cout << par[a][1] << '\n';
    }
    return 0;
}
```

## Distance Queries

```c++ Distance Queries
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
int in[200005], out[200005], par[200005][20];
vi g[200005];

void dfs(int rt, int pa, int &time) {
    in[rt] = time++;
    par[rt][0] = pa;
    for (int i = 0; rt!=1 && par[par[rt][i]][i] != -1; i++) par[rt][i + 1] = par[par[rt][i]][i];
    for (int i : g[rt]) {
        if (pa != i) dfs(i, rt, time);
    }
    out[rt] = time++;
}

int dis(int ch, int ac, int from) {
    if (ch == ac) return 0;
    while (par[ch][from] == -1) from--;
    while (from >= 0 && in[par[ch][from]] < in[ac]) from--;
    return (1 << from) + dis(par[ch][from], ac, from);
}

signed main() {
    ios;
    memset(par, -1, sizeof(par));
    cin >> n >> q;
    rep(i, 1, n - 1) {
        int a, b;
        cin >> a >> b;
        g[a].eb(b), g[b].eb(a);
    }
    dfs(1, -1, *(new int(0)));
    while (q--) {
        int a, b;
        cin >> a >> b;
        if (in[a] > in[b]) swap(a, b);
        int lca;
        if (out[b] <= out[a])
            lca = a;
        else {
            lca = a;
            rev(i, 19, 0) {
                if (par[lca][i] == -1) continue;
                if (in[par[lca][i]] < in[b] && out[b] < out[par[lca][i]]) continue;
                lca = par[lca][i];
            }
            lca = par[lca][0];
        }
        cout << dis(a, lca, 19) + dis(b, lca, 19) << '\n';
    }
    return 0;
}
```

## Counting Paths

```c++ Counting Paths
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
```

## Subtree Queries

```c++ Subtree Queries
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

struct BIT{
    int n;
    vi bit;
    BIT(int _n) : n(_n), bit(_n+1) {}
    void modify(int pos, int val){
        for(;pos<=n; pos+=pos&(-pos)) bit[pos]+=val;
    }
    int query(int pos){
        int ans = 0;
        for(;pos>0; pos-=pos&(-pos)) ans+=bit[pos];
        return ans;
    }
} bit(400005);

int n, q;
int in[200005], out[200005], w[200005];
vi g[200005];

void dfs(int rt, int pa, int &time){
    bit.modify(time, w[rt]);
    in[rt] = time++;
    for(int i : g[rt]) if(i != pa) dfs(i, rt, time);
    bit.modify(time, 0);
    out[rt] = time++;
}

signed main() {
    ios;
    cin >> n >> q;
    rep(i, 1, n) cin >> w[i];
    rep(i, 1, n-1){
        int a, b;
        cin >> a >> b;
        g[a].eb(b), g[b].eb(a);
    }
    dfs(1, 0, *(new int(1)));
    while(q--){
        int cmd, a, b;
        cin >> cmd >> a;
        if(cmd == 1) cin >> b, bit.modify(in[a], b-w[a]), w[a] = b;
        else cout << bit.query(out[a]) - bit.query(in[a]-1) << '\n';
    }
    return 0;
}
```

## Path Queries

```c++ Path Queries
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

struct BIT {
    int n;
    vi bit;
    BIT(int _n) : n(_n), bit(_n+1) {}
    void modify(int pos, int val){
        for(;pos<=n; pos+=pos&(-pos)) bit[pos]+=val;
    }
    int query(int pos){
        int ans = 0;
        for(;pos>0; pos-=pos&(-pos)) ans += bit[pos];
        return ans;
    }
} bit(400005);

int n, q;
int in[200005], out[200005], w[200005];
vi g[200005];

void dfs(int rt, int pa, int &time){
    bit.modify(time, w[rt]);
    in[rt] = time++;
    for(int i : g[rt]) if(pa != i) dfs(i, rt, time);
    bit.modify(time, -w[rt]);
    out[rt] = time++;
}

signed main() {
    ios;
    cin >> n >> q;
    rep(i, 1, n) cin >> w[i];
    rep(i, 1, n-1){
        int a, b;
        cin >> a >> b;
        g[a].eb(b), g[b].eb(a);
    }
    dfs(1, 0, *(new int(1)));
    while(q--){
        int cmd, a, b;
        cin >> cmd >> a;
        if(cmd == 1) cin >> b, bit.modify(in[a], b-w[a]), bit.modify(out[a], w[a]-b), w[a] = b;
        else cout << bit.query(in[a]) << '\n';
    }
    return 0;
}
```

## Path Queries II

```c++ Path Queries II
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

#define lc id * 2 + 1
#define rc id * 2 + 2
#define mid ((l + r) / 2)

int n, q, w[200005];
int seg[800005], dep[200005], par[200005], in[200005], boss[200005], sz[200005], h_child[200005];
vi g[200005];

void modify(int pos, int val, int l = 0, int r = n, int id = 0) {
    if (r - l == 1) {seg[id] = val; return;}
    if (pos >= mid)
        modify(pos, val, mid, r, rc);
    else
        modify(pos, val, l, mid, lc);
    seg[id] = max(seg[lc], seg[rc]);
}

int query(int L, int R, int l = 0, int r = n, int id = 0) {
    if (L == l && R == r) return seg[id];
    if (L >= mid) return query(L, R, mid, r, rc);
    if (R <= mid) return query(L, R, l, mid, lc);
    return max(query(L, mid, l, mid, lc), query(mid, R, mid, r, rc));
}

void dfs_pre(int rt, int pa) {
    dep[rt] = dep[pa] + 1;
    par[rt] = pa;
    sz[rt] = 1;
    int h_ch = -1, h_sz = -1;
    for (int i : g[rt]) {
        if (pa == i) continue;
        dfs_pre(i, rt);
        sz[rt] += sz[i];
        if(sz[i] > h_sz) h_sz=sz[i], h_ch=i;
    }
    h_child[rt] = h_ch;
}

void dfs_hld(int rt, int pa, int bos, int &time){
    modify(time, w[rt]);
    in[rt] = time++;
    boss[rt] = bos;
    if(h_child[rt] == -1) return;
    dfs_hld(h_child[rt], rt, bos, time);
    for(int i : g[rt]) if(i!=pa && i!=h_child[rt]) dfs_hld(i, rt, i, time);
}

int ask(int a, int b){
    int ans = 0;
    while(boss[a] != boss[b]) {
        if(dep[boss[a]] < dep[boss[b]]) swap(a, b);
        tomax(ans, query(in[boss[a]], in[a]+1));
        a = par[boss[a]];
    }
    if(dep[a]>dep[b]) swap(a, b);
    tomax(ans, query(in[a], in[b]+1));
    return ans;
}

signed main() {
    ios;
    cin >> n >> q;
    rep(i, 1, n) cin >> w[i];
    rep(i, 1, n-1){
        int a, b;
        cin >> a >> b;
        g[a].eb(b), g[b].eb(a);
    }
    dfs_pre(1, 1), dfs_hld(1,1,1, *(new int(0)));
    while(q--){
        int cmd, a, b;
        cin >> cmd >> a >> b;
        if(cmd == 1) modify(in[a], b);
        else cout << ask(a, b) << ' ';
    }
    return 0;
}
```

## Distinct Colors

File not found.

## Finding a Centroid

File not found.

## Fixed-Length Paths I

File not found.

## Fixed-Length Paths II

File not found.

## Files not found

Distinct Colors
Finding a Centroid
Fixed-Length Paths I
Fixed-Length Paths II
