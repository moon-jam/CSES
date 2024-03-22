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

/*
DP[i][j][k]  \rightarrow \text{ solution when we're currently at the point $(i,j) $ and first $i$ bits}\\\text{of $k$ correspond to $j$th column and rest of the bits belong to $j-1$ column}
*/

int mod = 1e9 + 7;
int n, m;
int dp[11][1003][1024];
int pos[] = {0, 1, 2, 4, 8, 16, 32, 64, 128, 256, 512};

signed main() {
    ios;
    cin >> n >> m;
    dp[n][0][(1 << n) - 1] = 1;
    rep(j, 1, m) {
        rep(k, 0, (1 << n) - 1) dp[0][j][k] = dp[n][j - 1][k];

        rep(i, 1, n) {
            rep(k, 0, (1 << n) - 1) {
                (dp[i][j][k] += dp[i - 1][j][k ^ pos[i]]) %= mod;
                if (i && (k & pos[i]) && (k & pos[i - 1]))
                    (dp[i][j][k] += dp[i - 1][j][k ^ pos[i - 1]]) %= mod;
            }
        }
    }
    cout << dp[n][m][(1 << n) - 1] % mod << '\n';
    return 0;
}
