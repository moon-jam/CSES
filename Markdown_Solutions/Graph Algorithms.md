# Graph Algorithms

## Counting Rooms

```c++ Counting Rooms
#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define F first
#define S second
#define rep(i,a,b) for(int i = a; i<=b; i++)
#define rev(i,a,b) for(int i = a; i>=b; i--)
#define tomax(a,b) (a)=max(a,b)
#define tomin(a,b) (a)=min(a,b)
#define pb push_back
#define eb emplace_back
#define ios ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int n, m, room=0;
bool is_floor[1003][1003];

void dfs(int i, int j){
    if(!is_floor[i][j]) return;
    is_floor[i][j]=0;
    dfs(i+1,j), dfs(i-1,j), dfs(i,j+1), dfs(i,j-1);
}

signed main(){
    // ios;
    cin >> n >> m;
    char tmp;
    memset(is_floor, 0, sizeof(is_floor));
    rep(i, 1, n)
        rep(j, 1, m)
            cin>>tmp, is_floor[i][j]=(tmp=='.');
    rep(i, 1, n)
        rep(j, 1, m)
            if(is_floor[i][j])
                room++, dfs(i, j);
    cout << room << '\n';
    return 0;
}
```

## Labyrinth

```c++ Labyrinth
#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define F first
#define S second
#define rep(i, a, b) for(int i = a; i<=b; ++i)
#define rev(i, a, b) for(int i = a; i>=b; --i)
#define tomax(a, b) (a)=max((a),(b))
#define tomin(a, b) (a)=min((a),(b))
#define all(a) a.begin(), a.end()
#define pob pop_back
#define pb push_back
#define eb emplace_back
#define ios ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int n, m;
pii a, b;
bool find_path = false;
bool graph[1003][1003];
queue<pii> q;
vector<char> path;
int dir[1003][1003];

signed main(){
    ios;
    memset(graph, 0, sizeof(graph));
    cin >> n >> m;
    char tmp;
    rep(i, 1, n)
        rep(j, 1, m)
            cin >> tmp, graph[j][i]=(tmp!='#'&&tmp!='A'),
            a = (tmp=='A' ? make_pair(j,i) : a),
            b = (tmp=='B' ? make_pair(j,i) : b);
    q.push(a);
    while(q.size()){
        int x = q.front().F, y = q.front().S; q.pop();
        if(x==b.F && y==b.S){ find_path=true; break;}
        if(graph[x-1][y]) dir[x-1][y]='L', graph[x-1][y]=0, q.push({x-1, y});
        if(graph[x+1][y]) dir[x+1][y]='R', graph[x+1][y]=0, q.push({x+1, y});
        if(graph[x][y-1]) dir[x][y-1]='U', graph[x][y-1]=0, q.push({x, y-1});
        if(graph[x][y+1]) dir[x][y+1]='D', graph[x][y+1]=0, q.push({x, y+1});
    }
    if(!find_path){cout << "NO\n"; return 0;}
    while(a!=b){
        path.pb(dir[b.F][b.S]);
        if(dir[b.F][b.S]=='L') b={b.F+1, b.S};
        else if(dir[b.F][b.S]=='R') b={b.F-1, b.S};
        else if(dir[b.F][b.S]=='U') b={b.F, b.S+1};
        else if(dir[b.F][b.S]=='D') b={b.F, b.S-1};
    }reverse(all(path));
    cout << "YES\n" << path.size() << '\n';
    for(char i : path) cout << i;
    cout << '\n';
    return 0;
}
```

## Building Roads

```c++ Building Roads
#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define F first
#define S second
#define rep(i, a, b) for(int i = a; i<=b; ++i)
#define rev(i, a, b) for(int i = a; i>=b; --i)
#define tomax(a, b) (a)=max((a),(b))
#define tomin(a, b) (a)=min((a),(b))
#define all(a) a.begin(), a.end()
#define pob pop_back
#define pb push_back
#define eb emplace_back
#define ios ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int bose[100005];

int fb(int ch){
    if(ch==bose[ch]) return ch;
    return bose[ch]=fb(bose[ch]);
}

signed main(){
    ios;
    // minimum spanning tree
    int n, m, connect=0;
    cin >> n >> m;
    vector<pii> E(m);
    for(pii &x : E) cin >> x.F >> x.S;
    rep(i, 1, n) bose[i]=i;
    for(pii path : E){
        if(connect==0 || fb(path.F) != fb(path.S))
            bose[fb(path.F)]=bose[fb(path.S)], connect++;
    }cout << n-1-connect << '\n';
    rep(i, 2, n){
        if(fb(i-1)!=fb(i))
            bose[fb(i-1)]=bose[fb(i)], cout << i-1 << ' ' << i << '\n';
    }
    return 0;
}

```

## Message Route

```c++ Message Route
#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define F first
#define S second
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define rev(i, a, b) for (int i = a; i >= b; --i)
#define tomax(a, b) (a) = max((a), (b))
#define tomin(a, b) (a) = min((a), (b))
#define all(a) a.begin(), a.end()
#define pob pop_back
#define pb push_back
#define eb emplace_back
#define ios ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int n, m, tmp1, tmp2;
int last_cpu[100005];
vector<int> E[100005];
vector<int> ans;

signed main() {
    ios;
    // BFS
    fill(last_cpu, last_cpu+100005, INT_MAX);
    cin >> n >> m;
    rep(i, 1, m) cin >> tmp1 >> tmp2, E[tmp1].eb(tmp2), E[tmp2].eb(tmp1);
    queue<int> q;
    q.push(1); last_cpu[1]=1;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(int x : E[cur])
            if(last_cpu[x]==INT_MAX) q.push(x), last_cpu[x]=cur;
    }
    if(last_cpu[n]!=INT_MAX){
        while(n!=1){
            ans.pb(n);
            n=last_cpu[n];
        }cout << ans.size()+1 << '\n';
        reverse(all(ans));
        cout << 1 << ' ';
        for(int x : ans) cout << x << ' ';
    }else{
        cout << "IMPOSSIBLE\n";
    }
    return 0;
}
```

## Building Teams

```c++ Building Teams
#include <bits/stdc++.h>
using namespace std;
/* TYPES  */
#define int long long
#define pii pair<int, int>
#define F first
#define S second
#define vi vector<int>
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
#define sp << " " <<
#define ios ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

vi E[100005];
vi team;
int n, m, tmp1, tmp2;
bool build_team = true;

void dfs(int r) {
    int draw = team[r] % 2 + 1;
    for (int i : E[r]) {
        if (team[i] == 0)
            team[i] = draw, dfs(i);
        else if (team[i] == draw)
            continue;
        else {
            build_team = false;
            return;
        }
    }
}

signed main() {
    ios;
    // bipartite graph
    cin >> n >> m;
    team.resize(n + 1), team.assign(n + 1, 0);
    rep(i, 1, m) {
        cin >> tmp1 >> tmp2;
        E[tmp1].eb(tmp2), E[tmp2].eb(tmp1);
    }
    rep(i, 1, n) {
        if (team[i] == 0) team[i] = 1, dfs(i);
    }
    if (build_team) {
        team.erase(team.begin());
        for (int i : team) cout << i << ' ';
    } else
        cout << "IMPOSSIBLE";
    return 0;
}
```

## Round Trip

```c++ Round Trip
#include <bits/stdc++.h>
using namespace std;
/* TYPES  */
#define int long long
#define pii pair<int, int>
#define F first
#define S second
#define vi vector<int>
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
#define sp << " " <<
#define ios ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

int n, m, min_l = INT_MAX, min_ls, min_le;
vi E[100005];
int lev[100005], parent[100005];
bool vis[100005];

void dfs(int u) {
    if (vis[u]) return;
    vis[u] = 1;
    for (int i : E[u]) {
        if (!vis[i])
            lev[i] = lev[u] + 1, parent[i] = u, dfs(i);
        else if(lev[u] > lev[i] && i != parent[u]){
            int path = lev[u] - lev[i] + 2;
            if (path < min_l) min_l=path, min_ls = u, min_le = i;
        }
    }
}

signed main() {
    ios;
    int tmp1, tmp2;
    memset(vis, 0, sizeof(vis));
    memset(lev, 0, sizeof(lev));
    cin >> n >> m;
    rep(i, 1, m) cin >> tmp1 >> tmp2, E[tmp1].eb(tmp2), E[tmp2].eb(tmp1);
    rep(i, 1, n) dfs(i);
    if(min_l == INT_MAX) cout << "IMPOSSIBLE\n";
    else{
        cout << min_l << '\n';
        tmp1 = min_ls;
        rep(i, 2, min_l){
            cout << min_ls << ' ';
            min_ls = parent[min_ls];
        }cout << tmp1 << '\n';
    }
    return 0;
}
```

## Monsters

```c++ Monsters
#include <bits/stdc++.h>
using namespace std;
/* TYPES  */
// #define int long long
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

bool vis[1003][1003];
bool vis_h[1003][1003];

signed main() {
    ios;
    int n, m;
    char g[1003][1003];
    cin >> n >> m;
    queue<pair<pii, bool> > pt;
    int from[1003][1003];
    bool ok = 0;
    pair<pii, bool> a;
    pii de;
    int dir_x[5] = {1, 0, -1, 0}, dir_y[5] = {0, 1, 0, -1};
    char dir[5] = {'D', 'R', 'U', 'L'};

    rep(i, 0, n - 1) rep(j, 0, m - 1) {
        cin >> g[i][j];
        if (g[i][j] == '#') vis[i][j] = 1;
        if (g[i][j] == 'M') pt.push({{i, j}, 0}), vis[i][j] = 1;
        if (g[i][j] == 'A') a = {{i, j}, 1}, vis_h[i][j] = 1;
    }
    pt.push(a);
    while (!pt.empty()) {
        // 0 U, 1 R, 2 D, 3 L
        auto x = pt.front();
        pt.pop();
        // cout << x.F.F sp x.F.S << '\n';
        if (!x.S) {
            rep(i, 0, 3) {
                int xx = x.F.F + dir_x[i], yy = x.F.S + dir_y[i];
                if (!vis[xx][yy] && xx >= 0 && xx <= n - 1 && yy >= 0 &&
                    yy <= m - 1) {
                    pt.push({{xx, yy}, 0});
                    vis[xx][yy] = 1;
                }
            }
        } else if (x.S && (x.F.F == 0 || x.F.S == 0 || x.F.F == n - 1 ||
                           x.F.S == m - 1)) {
            // cout << x.F.F sp x.F.S << '\n';
            ok = 1;
            de = {x.F.F, x.F.S};
            break;
        } else if (x.S) {
            // cout << x.F.F sp x.F.S << '\n';
            // cout << '\n';
            rep(i, 0, 3) {
                if (!vis[x.F.F + dir_x[i]][x.F.S + dir_y[i]] &&
                    !vis_h[x.F.F + dir_x[i]][x.F.S + dir_y[i]]) {
                    pt.push({{x.F.F + dir_x[i], x.F.S + dir_y[i]}, 1});
                    vis_h[x.F.F + dir_x[i]][x.F.S + dir_y[i]] = 1;
                    from[x.F.F + dir_x[i]][x.F.S + dir_y[i]] = i;
                }
            }
        }
    }
    if (!ok)
        cout << "NO\n";
    else {
        cout << "YES\n";
        vector<char> ans;
        while (de.F != a.F.F || de.S != a.F.S) {
            // cout << de.F sp de.S << '\n';
            int tmpF = de.F;
            ans.eb(dir[from[de.F][de.S]]);
            de.F -= dir_x[from[de.F][de.S]];
            de.S -= dir_y[from[tmpF][de.S]];
            // cout << de.F sp de.S << "\n\n";
        }
        cout << ans.size() << '\n';
        reverse(all(ans));
        for (char i : ans) cout << i;
    }
    return 0;
}
```

## Shortest Routes I

File not found.

## Shortest Routes II

File not found.

## High Score

File not found.

## Flight Discount

File not found.

## Cycle Finding

File not found.

## Flight Routes

File not found.

## Round Trip II

File not found.

## Course Schedule

File not found.

## Longest Flight Route

File not found.

## Game Routes

File not found.

## Investigation

File not found.

## Planets Queries I

File not found.

## Planets Queries II

File not found.

## Planets Cycles

File not found.

## Road Reparation

File not found.

## Road Construction

File not found.

## Flight Routes Check

File not found.

## Planets and Kingdoms

File not found.

## Giant Pizza

File not found.

## Coin Collector

File not found.

## Mail Delivery

File not found.

## De Bruijn Sequence

File not found.

## Teleporters Path

File not found.

## Hamiltonian Flights

File not found.

## Knight's Tour

File not found.

## Download Speed

File not found.

## Police Chase

File not found.

## School Dance

File not found.

## Distinct Routes

File not found.



# Files not found

Shortest Routes I
Shortest Routes II
High Score
Flight Discount
Cycle Finding
Flight Routes
Round Trip II
Course Schedule
Longest Flight Route
Game Routes
Investigation
Planets Queries I
Planets Queries II
Planets Cycles
Road Reparation
Road Construction
Flight Routes Check
Planets and Kingdoms
Giant Pizza
Coin Collector
Mail Delivery
De Bruijn Sequence
Teleporters Path
Hamiltonian Flights
Knight's Tour
Download Speed
Police Chase
School Dance
Distinct Routes