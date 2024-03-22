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
int dp[1024][2];
int pos[] = {0, 1, 2, 4, 8, 16, 32, 64, 128, 256, 512};
const int M = 1e9 + 7;
bool p = 0;

signed main() {
    ios;
    cin >> n >> m;
    dp[(1 << n) - 1][p] = 1;
    rep(j, 1, m) {
        rep(i, 1, n) {
            rep(k, 0, (1 << n) - 1) {
                (dp[k][!p] = dp[k ^ pos[i]][p]) %= mod;
                if (i && (k & pos[i]) && (k & pos[i - 1]))
                    (dp[k][!p] += dp[k ^ pos[i - 1]][p]) %= mod;
            }
            p = !p;
        }
    }
    cout << dp[(1 << n) - 1][p] % mod << '\n';
    return 0;
}
