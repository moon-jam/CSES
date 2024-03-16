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

int n, m, dp[5003][5003];
string s1, s2;

signed main() {
    ios;
    cin >> s1 >> s2;
    n = s1.size();
    m = s2.size();
    dp[0][0] = (s1[0] != s2[0]);
    rep(i, 1, n-1){
        if(dp[i-1][0] == i && s1[i] == s2[0]) dp[i][0] = i;
        else dp[i][0] = dp[i-1][0]+1; 
    }
    rep(i, 1, m-1){
        if(dp[0][i-1] == i && s1[0] == s2[i]) dp[0][i] = i;
        else dp[0][i] = dp[0][i-1]+1; 
    }
    rep(i, 1, n-1){
        rep(j, 1, m-1){
            dp[i][j] = min(dp[i-1][j-1] + (s1[i] != s2[j]), min(dp[i-1][j]+1, dp[i][j-1]+1));
        }
    }

    cout << dp[n-1][m-1];
    return 0;
}