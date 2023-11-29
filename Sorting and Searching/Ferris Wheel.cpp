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

signed main() {
    ios;
    int n, x, ans = 0;
    cin >> n >> x;
    vector<int> p(n);
    for (int& i : p) cin >> i;
    sort(all(p));
    for (int l = 0, r = n - 1; r >= l;) {
        if (p[l] + p[r] <= x)
            ans++, l++, r--;
        else if (p[l] + p[r] >= x)
            ans++, r--;
    }
    cout << ans << '\n';
    return 0;
}