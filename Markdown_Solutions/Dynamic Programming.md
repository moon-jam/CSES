# Dynamic Programming

## Dice Combinations

```c++ Dice Combinations
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

```

## Minimizing Coins

```c++ Minimizing Coins
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

```

## Coin Combinations I

```c++ Coin Combinations I
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
    rep(i, 0, n-1) cin >> c[i];
    rep(i, 1, x){
        rep(j, 0, n-1)
            if(i-c[j]>=0)
                dp[i]+=dp[i-c[j]], dp[i]%=mod;
                //每個最多用i次加到dp[i]的方法數
    }
    cout << dp[x] << '\n';
    return 0;
}

```

## Coin Combinations II

```c++ Coin Combinations II
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

```

## Removing Digits

```c++ Removing Digits
#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define F first
#define S second
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define rev(i, a, b) for (int i = a; i >= b; --i)
#define tomax(a, b) (a) = max((a), (b))
#define tomin(a, b) (a) = min((a), (b))
#define all(a) a.begin(), a.end()
#define pob pop_back
#define pb push_back
#define eb emplace_back
#define ios ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int step[1000006];

int get_step(int num) {
    if (num < 10) return 1;
    if (step[num] != INT_MAX) return step[num];
    for (int dig = num % 10, pos = 1; pos <= num;
         pos *= 10, dig = (num % (pos * 10)) / pos) {
        if (num - dig != num) tomin(step[num], get_step(num - dig) + 1);
    }
    return step[num];
}

signed main() {
    ios;
    int n;
    cin >> n;
    fill(step, step + n + 1, INT_MAX);
    cout << get_step(n) << '\n';
    return 0;
}
```

## Grid Paths

```c++ Grid Paths
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

int mod = 1e9 + 7;
int dp[1003][1003], n;
bool vis[1003][1003];

int dfs(int i, int j) {
    // cout << i sp j sp vis[i][j] << '\n';
    if (vis[i][j]) return dp[i][j];
    if (i == n && j == n) return dp[i][j] = 1;
    vis[i][j] = 1;
    dp[i][j] = (dfs(i + 1, j)%mod + dfs(i, j + 1)%mod)%mod;
    return dp[i][j];
}

signed main() {
    ios;
    char tmp;
    cin >> n;
    memset(vis, 1, sizeof(vis));
    rep(i, 1, n) rep(j, 1, n) cin >> tmp, vis[i][j] = (tmp != '.');
    cout << dfs(1, 1)%mod << '\n';
    return 0;
}
```

## Book Shop

```c++ Book Shop
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

signed main() {
    ios;
    int n, x;
    cin >> n >> x;
    vii book(n);
    vi dp(x + 1, 0);
    for (pii &i : book) cin >> i.F;
    for (pii &i : book) cin >> i.S;
    for (pii i : book) {
        rev(j, x, i.F) { tomax(dp[j], dp[j - i.F] + i.S); }
    }
    cout << dp[x] << '\n';
    return 0;
}

```

## Array Description

```c++ Array Description
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

int mod = 1e9 + 7;
int n, m;
int dp[100005][105], arr[100005];

signed main() {
    ios;
    cin >> n >> m;

    rep(i, 1, n) cin >> arr[i];
    if (!arr[1]) rep(i, 1, m) dp[1][i] = 1;
    else dp[1][arr[1]] = 1;

    rep(i, 2, n) {
        if (!arr[i]) {
            rep(j, 1, m) {
                dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % mod;
                dp[i][j] = (dp[i][j] + dp[i - 1][j]) % mod;
                dp[i][j] = (dp[i][j] + dp[i - 1][j + 1]) % mod;
            }
        } else {
            dp[i][arr[i]] = (dp[i][arr[i]] + dp[i - 1][arr[i] - 1]) % mod;
            dp[i][arr[i]] = (dp[i][arr[i]] + dp[i - 1][arr[i]]) % mod;
            dp[i][arr[i]] = (dp[i][arr[i]] + dp[i - 1][arr[i] + 1]) % mod;
        }
    }
    int ans = 0;
    rep(j, 1, m) ans = (ans + dp[n][j]) % mod;
    cout << ans << '\n';
    return 0;
}
```

## Counting Towers

```c++ Counting Towers
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

int mod = 1e9 + 7;
int dp[1000006][4]; // -- , oo, ox, xo (ox = xo)
int n, t;

void build() {
    dp[1][0] = dp[1][1] = dp[1][2] = 1;
    // dp[i][0] = dp[i-1][0]+dp[i-1][1]
    // dp[i][1] = dp[i-1][0]+dp[i-1][1]*3
    rep(i, 2, 1e6){
        dp[i][0] = (dp[i-1][0]*2 + dp[i-1][1])%mod;
        dp[i][1] = (dp[i-1][0]+dp[i-1][1]*4)%mod;
    }
}

signed main() {
    ios;
    build();
    cin >> t;
    while (t--) {
        cin >> n;
        cout << (dp[n][0] + dp[n][1])%mod << '\n';
    }
    return 0;
}

```

## Edit Distance

```c++ Edit Distance
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
```

## Rectangle Cutting

```c++ Rectangle Cutting
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

signed main() {
    ios;
    int n, m, dp[502][502];
    cin >> n >> m;
    rep(i, 1, n) {
        rep(j, 1, m) {
            if (i == j)
                dp[i][j] = 0;
            else {
                dp[i][j] = 1e9;
                rep(k, 1, i) tomin(dp[i][j], dp[k][j] + dp[i - k][j] + 1);
                rep(k, 1, j) tomin(dp[i][j], dp[i][k] + dp[i][j - k] + 1);
            }
        }
    }
    cout << dp[n][m] << '\n';
    return 0;
}
```

## Money Sums

```c++ Money Sums
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
```

## Removal Game

```c++ Removal Game
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
```

## Two Sets II

```c++ Two Sets II
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
```

## Increasing Subsequence

File not found.

## Projects

File not found.

## Elevator Rides

```c++ Elevator Rides
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

```

## Counting Tilings

File not found.

## Counting Numbers

File not found.



# Files not found

Increasing Subsequence
Projects
Counting Tilings
Counting Numbers