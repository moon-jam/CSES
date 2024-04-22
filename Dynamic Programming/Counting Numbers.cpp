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

int a, b;
int dp[20][10], sum[20];

void pre() {
    rep(i, 0, 9) dp[1][i] = 1;
    sum[1] = 10;
    rep(i, 2, 18) {
        rep(j, 0, 9) {
            rep(k, 0, 9) if (j != k) dp[i][j] += dp[i - 1][k];
            if (j) sum[i] += dp[i][j];
        }
    }
}

int cal(int x) {
    if (x <= 0) return x + 1;

    int ans = 0;
    vector<int> s;
    while (x > 0) s.eb(x % 10), x /= 10;
    int n = s.size();
    s.eb(0);
    reverse(s.begin(), s.end());

    rev(i, n - 1, 1) ans += sum[i];
    rep(i, 1, s[1] - 1) ans += dp[n][i];

    rep(i, 1, n - 1) {
        rep(j, 0, s[i + 1] - 1) if (j != s[i]) ans += dp[n - i][j];
        if (s[i + 1] == s[i]) break;
    }
    bool ok = true;
    rep(i, 1, n - 1) {
        if (s[i + 1] == s[i]) ok = false;
    }
    ans += ok;

    return ans;
}

signed main() {
    ios;
    pre();
    cin >> a >> b;
    cout << cal(b) - cal(a - 1) << '\n';
    return 0;
}
