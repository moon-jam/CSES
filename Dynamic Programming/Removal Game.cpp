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

int n;
int dp[5003][5003];
int arr[5003], pre[5003];

signed main() {
    ios;
    cin >> n;
    int ans = -1e18;
    rep(i, 1, n) cin >> arr[i], pre[i] = pre[i - 1] + arr[i];
    rep(i, 1, n) {
        rep(j, 1, n - i + 1) {
            if (i == 1)
                dp[j][j] = arr[j];
            else {
                dp[j][j + i - 1] =
                    max(arr[j] + pre[j + i - 1] - pre[j] - dp[j + 1][j + i - 1],
                        pre[i + j - 2] - pre[j - 1] - dp[j][i + j - 2] +
                            arr[i + j - 1]);
            }
        }
    }
    cout << dp[1][n] << '\n';
    return 0;
}