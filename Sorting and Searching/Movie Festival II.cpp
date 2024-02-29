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
    int n, k, ans = 0;
    cin >> n >> k;
    vii arr(n);
    multiset<int> ms;
    for (pii &i : arr) cin >> i.F >> i.S;
    sort(all(arr), [](pii a, pii b) { return a.S < b.S; });
    rep(i, 1, k) ms.insert(-1);
    rep(i, 0, n - 1) {
        while (i < n && arr[i].F < *ms.begin()) i++;
        if (i == n) break;
        ms.erase(prev(ms.upper_bound(arr[i].F)));
        ms.insert(arr[i].S);
        ans++;
    }
    cout << ans << '\n';
    return 0;
}