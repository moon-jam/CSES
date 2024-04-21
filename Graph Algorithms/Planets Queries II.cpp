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
int go[200005];
vi rgo[200005];
int boss[200005];
int sizeC[200005];
int idxC[200005];  // from is big
int idxA[200005];  // from is big
bool inC[200005];
bool tmpC[200005];
bool vis[200005];

int find_boss(int ch) {
    if (ch == boss[ch]) return ch;
    return boss[ch] = find_boss(boss[ch]);
}

int dfs(int rt) {
    if (vis[rt]) return rt;
    vis[rt] = 1;
    int flag = dfs(go[rt]);
    if (!sizeC[find_boss(rt)]) {
        inC[rt] = 1;
        idxC[rt] = idxC[go[rt]] + 1;
        if (flag == rt) sizeC[find_boss(rt)] = idxC[rt];
    }
    return flag;
}

void dfs2(int rt, int id) {
    idxA[rt] = id;
    for (int i : rgo[rt])
        if (!inC[i]) dfs2(i, id + 1);
}

int ch[200005][31];  //[i][j] -> 2^j th child of i

void build() { rep(i, 1, 30) rep(j, 1, n) ch[j][i] = ch[ch[j][i - 1]][i - 1]; }

int query(int x, int k) {
    for (int i = 0; k != 0; k >>= 1, i++)
        if (k & 1) x = ch[x][i];
    return x;
}

signed main() {
    ios;
    cin >> n >> q;
    rep(i, 1, n) boss[i] = i;
    rep(i, 1, n) cin >> go[i], rgo[go[i]].eb(i), boss[find_boss(i)] = boss[find_boss(go[i])], ch[i][0] = go[i];
    rep(i, 1, n) dfs(i);
    rep(i, 1, n) if (inC[i]) dfs2(i, 0);
    build();
    while (q--) {
        int a, b;
        cin >> a >> b;
        if (find_boss(a) != find_boss(b))
            cout << "-1\n";
        else {
            if (inC[a] && inC[b])
                cout << (idxC[a] - idxC[b] + sizeC[find_boss(a)]) % sizeC[find_boss(a)] << '\n';
            else if (!inC[a] && inC[b])
                cout << idxA[a] + (idxC[query(a, idxA[a])] - idxC[b] + sizeC[find_boss(a)]) % sizeC[find_boss(a)] << '\n';
            else if (idxA[a] >= idxA[b] && query(a, idxA[a] - idxA[b]) == b)
                cout << idxA[a] - idxA[b] << '\n';
            else
                cout << "-1\n";
        }
    }
    return 0;
}