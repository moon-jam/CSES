#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define F first
#define S second
#define rep(i, a, b) for(int i = a; i<=b; ++i)
#define rev(i, a, b) for(int i = a; i>=b; --i)
#define tomax(a, b) (a)=max((a),(b))
#define tomin(a, b) (a)=min((a),(b))
#define all(a) a.begin(), a.end()
#define pb push_back
#define eb emplace_back
#define ios ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

// dp[20][1<<20], dp[i][j]在0~i台電梯上可以用j的選擇方法搭i電梯的重量(不行inf)
// dp[i][0] = 0
// dp[i][1<<k] = w[k]
// other = inf
// dp[i][j] = min((dp[i-1][j]<inf), (dp[i][j & ~(1<<k)]+w[k]<=x ? dp[i-1][j & ~(1<<k)]+w[k] : inf)), k=0~n-1
// ans = (dp[min_i][1<<20]!=inf)

int dp[22][1<<21];
int n, w[22], x, inf=3e10;

signed main(){
    // ios;
    cin >> n >> x;
    int ans = n;
    rep(i, 0, n-1)
        rep(j, 0, 1<<n)
            dp[i][j]=inf;
    rep(i, 0, n-1) {
        cin >> w[i];
        dp[i][0]=0;
        rep(k, 0, n-1) dp[i][1<<k]=w[k];
    }dp[n][0]=0; rep(k, 0, n-1) dp[n][1<<k]=w[k];
    build()
    cout << ans;
    return 0;
}
