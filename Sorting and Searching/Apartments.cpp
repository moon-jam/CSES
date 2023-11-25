#include <bits/stdc++.h>
// #define int long long
#define pii pair<int, int>
#define F first
#define S second
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define rev(i, a, b) for (int i = a; i >= b; i--)
#define tomax(a, b) (a) = max((a), (b))
#define tomin(a, b) (a) = min((a), (b))
#define pb push_back
#define eb emplace_back
#define all(a) a.begin(), a.end()
#define ios ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

signed main()
{
    ios;
    int n, m, k, ans = 0, a[200005], b[200005];
    cin >> n >> m >> k;
    rep(i, 1, n) cin >> a[i];
    rep(i, 1, m) cin >> b[i];
    sort(a + 1, a + n + 1);
    sort(b + 1, b + m + 1);
    for (int i = 1, j = 1; i <= n && j <= m;) {
        if (a[i] + k >= b[j] && a[i] - k <= b[j])
            i++, j++, ans++;
        else if (a[i] + k < b[j])
            i++;
        else if (a[i] - k > b[j])
            j++;
    }
    cout << ans << '\n';
    return 0;
}