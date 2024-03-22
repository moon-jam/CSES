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
int dp[11][1003][1 << 11];

signed main() {
    ios;
    int n, m;
    cin >> n >> m;
    memset(dp, 0, sizeof(dp));
    dp[n][0][0] = 1;
    rep(i, 1, m) {
        rep(j, 0, (1 << n) - 1) dp[0][i][j << 1] = dp[n][i - 1][j];

        rep(j, 1, n) {
            int x = 1 << (j - 1);
            int y = 1 << j;
            rep(set, 0, (1 << (n + 1)) - 1) {
                dp[j - 1][i][set] %= mod;
                if ((set & x) && (set & y)) continue;
                if (set & x)
                    dp[j][i][set ^ x] += dp[j - 1][i][set];
                else if (set & y)
                    dp[j][i][set ^ y] += dp[j - 1][i][set];
                else {
                    dp[j][i][set ^ x] += dp[j - 1][i][set];
                    dp[j][i][set ^ y] += dp[j - 1][i][set];
                }
            }
        }
    }
    cout << dp[n][m][0] % mod << '\n';
    return 0;
}

