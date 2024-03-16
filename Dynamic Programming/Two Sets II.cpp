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

int dp[64000];
int mod = 1e9+7;

signed main() {
    ios;
    int n, goal;
    cin >> n;
    goal = n * (n + 1) / 2;
    if(goal & 1) {cout << 0 << '\n'; return 0;}
    else goal >>= 1;
    dp[0] = 1;
    rep(i, 1, n) {
        rev(j, goal, i)
            dp[j] = (dp[j] + dp[j-i]) % (mod*2);
    }
    cout << (dp[goal] >> 1) << '\n';
    return 0;
}