#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define F first
#define S second
#define rep(i, a, b) for(int i = a; i<=b; i++)
#define rev(i, a, b) for(int i = a; i>=b; i--)
#define tomax(a,b) (a)=max((a),(b))
#define tomin(a,b) (a)=min((a),(b))
#define pb push_back
#define eb emplace_back
#define all(a) a.begin(), a.end()
#define ios ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

const int mod = 1e9 + 7;

signed main(){
    ios;
    int n, dp[1000006], pre = 1;
    cin >> n;
    fill(dp, dp+n+3, 0);
    rep(i, 1, 6){
        dp[i] = pre;
        pre += dp[i];
    }rep(i, 7, n){
        rep(j, i-6, i-1)
            dp[i]+=dp[j], dp[i]%=mod;
    }cout << dp[n] << '\n';
    return 0;
}
// 1 1 1 1 1 1 2
// 1 1 1 1 1 2 1
