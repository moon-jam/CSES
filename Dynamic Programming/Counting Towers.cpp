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
int dp[1000006][4]; // -- , oo, ox, xo (ox = xo)
int n, t;

void build() {
    dp[1][0] = dp[1][1] = dp[1][2] = 1;
    // dp[i][0] = dp[i-1][0]+dp[i-1][1]
    // dp[i][1] = dp[i-1][0]+dp[i-1][1]*3
    rep(i, 2, 1e6){
        dp[i][0] = (dp[i-1][0]*2 + dp[i-1][1])%mod;
        dp[i][1] = (dp[i-1][0]+dp[i-1][1]*4)%mod;
    }
}

signed main() {
    ios;
    build();
    cin >> t;
    while (t--) {
        cin >> n;
        cout << (dp[n][0] + dp[n][1])%mod << '\n';
    }
    return 0;
}
