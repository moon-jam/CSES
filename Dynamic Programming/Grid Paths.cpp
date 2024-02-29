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

int mod = 1e9 + 7;
int dp[1003][1003], n;
bool vis[1003][1003];

int dfs(int i, int j) {
    // cout << i sp j sp vis[i][j] << '\n';
    if (vis[i][j]) return dp[i][j];
    if (i == n && j == n) return dp[i][j] = 1;
    vis[i][j] = 1;
    dp[i][j] = (dfs(i + 1, j)%mod + dfs(i, j + 1)%mod)%mod;
    return dp[i][j];
}

signed main() {
    ios;
    char tmp;
    cin >> n;
    memset(vis, 1, sizeof(vis));
    rep(i, 1, n) rep(j, 1, n) cin >> tmp, vis[i][j] = (tmp != '.');
    cout << dfs(1, 1)%mod << '\n';
    return 0;
}