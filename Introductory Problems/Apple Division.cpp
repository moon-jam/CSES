#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define F first
#define S second
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define rev(i, a, b) for (int i = a; i >= b; i--)
#define tomax(a, b) (a) = max((a), (b))
#define tomin(a, b) (a) = min((a), (b))
#define pb push_back
#define eb emplace_back
#define ios ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

signed main() {
    ios;
    int n, app[21];
    cin >> n;
    rep(i, 0, n - 1) cin >> app[i];
    int ans = 1e11;
    rep(i, 0, (1 << n) - 1) {
        int a = 0, b = 0;
        rep(j, 0, n - 1) a += app[j] * ((i >> j) & 1),
            b += app[j] * (((i >> j) & 1) ^ 1);
        tomin(ans, abs(a - b));
    }
    cout << ans << '\n';
    return 0;
}
