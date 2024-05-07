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

File not found.

## Company Queries II

File not found.

## Distance Queries

File not found.

## Counting Paths

File not found.

## Subtree Queries

File not found.

## Path Queries

File not found.

## Path Queries II

File not found.

## Distinct Colors

File not found.

## Finding a Centroid

File not found.

## Fixed-Length Paths I

File not found.

## Fixed-Length Paths II

File not found.

## Files not found

Company Queries I
Company Queries II
Distance Queries
Counting Paths
Subtree Queries
Path Queries
Path Queries II
Distinct Colors
Finding a Centroid
Fixed-Length Paths I
Fixed-Length Paths II
