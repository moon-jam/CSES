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

int n, m, q, a, b, c;
int dp[502][502];

signed main() {
    ios;
    rep(i, 0, 500) rep(j, 0, 500) dp[i][j] = 1e18 * (i!=j);
    cin >> n >> m >> q;
    rep(i, 1, m) {
        cin >> a >> b >> c;
        dp[a][b] = dp[b][a] = min(dp[a][b], c);
    }
    rep(k, 1, n) rep(i, 1, n) rep(j, 1, n) tomin(dp[i][j], dp[i][k] + dp[k][j]);
    while (q--) {
        cin >> a >> b;
        if (dp[a][b] == 1e18)
            cout << "-1\n";
        else
            cout << dp[a][b] << '\n';
    }
    return 0;
}