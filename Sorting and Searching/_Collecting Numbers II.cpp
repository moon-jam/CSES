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
#define sp << " " <<
#define ios ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

signed main() {
    // ios;
    int n, m, ans = 0, idx = 0;
    cin >> n >> m;
    vi arr(n), r(n + 1);
    for (int &i : arr) cin >> i, r[i] = idx++;
    rep(i, 1, n) {
        while (i < n && r[i + 1] > r[i]) i++;
        ans++;
    }
    while (m--) {
        int a, b;
        cin >> a >> b;
        if (a < b)
            ans += (arr[a-1] > arr[b-1]) ? 1 : -1;
        else
            ans -= (arr[a-1] > arr[b-1]) ? 1 : -1;
        swap(arr[r[a]], arr[r[b]]);
        cout << ans << '\n';
    }
    return 0;
}