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

const int MAX = 1e9;

signed main(){
    ios;
    int n, x, dp[1000006], c[102];
    cin >> n >> x;
    fill(dp, dp+x+1, MAX);
    dp[0]=0;
    rep(i, 0, n-1){
        cin >> c[i];
        for (int j = 0; j+c[i] <= x; j++){
            dp[j+c[i]] = min(dp[j+c[i]], dp[j]+1);
        }
    }
    if(dp[x]!=MAX) cout << dp[x] << '\n';
    else cout << "-1\n";
    return 0;
}
