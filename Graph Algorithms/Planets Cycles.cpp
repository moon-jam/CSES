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
int boss[200005];
int go[200005];
vi rgo[200005];
int idxA[200005];
int sizeC[200005];
bool inC[200005];
bool vis[200005];

int find_boss(int ch) {
    if (ch == boss[ch]) return ch;
    return boss[ch] = find_boss(boss[ch]);
}

int dfs(int rt, int &cSize) {
    if (vis[rt]) return rt;
    vis[rt] = 1;
    int flag = dfs(go[rt], cSize);
    if (!sizeC[find_boss(rt)]) {
        inC[rt] = 1;
        cSize++;
        if (rt == flag) sizeC[find_boss(rt)] = cSize;
    }
    return flag;
}

void dfs2(int rt, int id) {
    idxA[rt] = id;
    for (int i : rgo[rt])
        if (!inC[i]) dfs2(i, id + 1);
}

signed main() {
    ios;
    cin >> n;
    rep(i, 1, n) boss[i] = i;
    rep(i, 1, n) cin >> go[i], rgo[go[i]].eb(i), boss[find_boss(i)] = boss[find_boss(go[i])];
    for (int i = 1, cSize = 0; i <= n; i++, cSize = 0) dfs(i, cSize);
    rep(i, 1, n) if (inC[i]) dfs2(i, 0);
    rep(i, 1, n) { cout << idxA[i] + sizeC[find_boss(i)] << ' '; }
    return 0;
}