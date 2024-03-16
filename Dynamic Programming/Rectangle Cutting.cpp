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

signed main() {
    ios;
    int n, m, dp[502][502];
    cin >> n >> m;
    rep(i, 1, n) {
        rep(j, 1, m) {
            if (i == j)
                dp[i][j] = 0;
            else {
                dp[i][j] = 1e9;
                rep(k, 1, i) tomin(dp[i][j], dp[k][j] + dp[i - k][j] + 1);
                rep(k, 1, j) tomin(dp[i][j], dp[i][k] + dp[i][j - k] + 1);
            }
        }
    }
    cout << dp[n][m] << '\n';
    return 0;
}