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
int dp[21][2000006];
int g[21][21];

signed main() {
    ios;
    cin >> n >> m;
    rep(i, 1, m) {
        int a, b;
        cin >> a >> b;
        g[a][b]++;
    }
    dp[1][1] = 1;
    // int op = 0;
    rep(i, 1, (1 << n) - 1) {
        rep(j, 1, n) {
            int pos = (1 << (j - 1));
            if (!(i & pos)) continue;
            rep(k, 1, n) {
                if (!g[k][j]) continue;
                (dp[j][i] += dp[k][i^pos] * g[k][j]);
                // op++;
            }
            dp[j][i] %= mod;
        }
        i++;  // first digit must be 1 because path start at one.
    }
    cout << dp[n][(1 << n) - 1] % mod << '\n';
    return 0;
}
