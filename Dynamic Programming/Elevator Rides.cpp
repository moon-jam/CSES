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

void bit_out(int num, int digit, bool reverse){
    if(!reverse)
        rev(i, digit-1, 0)
            cout << ((num & (1<<i))!=0) << ' ';
    else rep(i, 0, digit-1)
            cout << ((num & (1<<i))!=0) << ' ';
    cout << '\n';
}

// dp[i][0] : minimum rides
// dp[i][1] : minimum weight

// init
// dp[i][0] = n
// dp[i][1] = INT_MAX
// dp[0][0] = 1, dp[0][1] = 0

// new_weight = dp[i^(1<<j)][1] + w[j]              , j in i
// dp[i][0] = min(dp[i^(1<<j)][0] + new_weight>x)   , j in i
// dp[i][1] = dp[i][0]_update ? min(dp[i][1], new_weight) : dp[i][1]    , dp[i][0]==dp[i][0]_ori && new_weight<=x
// dp[i][1] = dp[i][0]_update ? new_weight : dp[i][1]                   , dp[i][0]<dp[i][0]_ori && new_weight<=x
// dp[i][1] = dp[i][0]_update ? w[j] : dp[i][1]                         , dp[i][0]<=dp[i][0]_ori && new_weight>x

int dp[1<<21][3];
int n, w[22], x;

signed main(){
    ios;
    cin >> n >> x;
    rep(i, 0, n-1) cin >> w[i];
    rep(i, 0, 1<<n)
        dp[i][0]=n, dp[i][1]=INT_MAX;
    dp[0][0] = 1, dp[0][1] = 0;
    rep(i, 1, (1<<n)-1){
        rep(j, 0, n-1){
            if(i & (1<<j)){
                int new_weight = (dp[i^(1<<j)][1]) + w[j];
                if(dp[i][0] >= dp[i^(1<<j)][0]+(new_weight>x)){
                    if(dp[i][0] == dp[i^(1<<j)][0] && (new_weight<=x))
                        dp[i][1] = min(dp[i][1], new_weight);
                    else dp[i][1] = new_weight>x ? w[j] : new_weight;
                    dp[i][0] = dp[i^(1<<j)][0]+(new_weight>x);
                }
            }
        }//bit_out(i, n, 1), cout << dp[i][0] << ' ' << dp[i][1] << '\n';
    }
    cout << dp[(1<<n)-1][0] << '\n';
    return 0;
}
