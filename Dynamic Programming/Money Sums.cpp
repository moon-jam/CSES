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
int arr[1003];
bool dp[102][100005];

signed main() {
    ios;
    cin >> n;
    rep(i, 1, n) cin >> arr[i];
    rep(i, 1, n){
        rep(j, 1, 100000){
            if(dp[i-1][j]) dp[i][j] = dp[i][j+arr[i]] = 1;
        }
        dp[i][arr[i]] = 1;
    }
    vi ans;
    rep(i, 1, 100000) if(dp[n][i]) ans.eb(i);
    cout << ans.size() << '\n';
    for(int i : ans) cout << i << ' ';
    return 0;
}