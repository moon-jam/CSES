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

const int mod = 1e9+7;

signed main(){
    ios;
    int n, x, dp[1000006], c[102];
    cin >> n >> x;
    memset(dp, 0, sizeof(dp));
    dp[0]=1;
    rep(i, 0, n-1){
        cin >> c[i];
        for (int j = 0; j+c[i] <= x; j++){
            dp[j+c[i]]+=dp[j], dp[j+c[i]]%=mod;
            //用第0~i個數字加到任意可達的組合數
        }
    }
    cout << dp[x] << '\n';
    return 0;
}
