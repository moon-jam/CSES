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