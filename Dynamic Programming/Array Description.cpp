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
int n, m;
int dp[100005][105], arr[100005];

signed main() {
    ios;
    cin >> n >> m;

    rep(i, 1, n) cin >> arr[i];
    if (!arr[1]) rep(i, 1, m) dp[1][i] = 1;
    else dp[1][arr[1]] = 1;

    rep(i, 2, n) {
        if (!arr[i]) {
            rep(j, 1, m) {
                dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % mod;
                dp[i][j] = (dp[i][j] + dp[i - 1][j]) % mod;
                dp[i][j] = (dp[i][j] + dp[i - 1][j + 1]) % mod;
            }
        } else {
            dp[i][arr[i]] = (dp[i][arr[i]] + dp[i - 1][arr[i] - 1]) % mod;
            dp[i][arr[i]] = (dp[i][arr[i]] + dp[i - 1][arr[i]]) % mod;
            dp[i][arr[i]] = (dp[i][arr[i]] + dp[i - 1][arr[i] + 1]) % mod;
        }
    }
    int ans = 0;
    rep(j, 1, m) ans = (ans + dp[n][j]) % mod;
    cout << ans << '\n';
    return 0;
}