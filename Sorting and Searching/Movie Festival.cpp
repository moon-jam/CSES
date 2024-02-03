#include <bits/stdc++.h>
using namespace std;
/* TYPES  */
#define int long long
#define pii pair<int, int>
#define F first
#define S second
#define vi vector<int>
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
    ios;
    int n;
    cin >> n;
    vector<pii> m(n);
    for (pii &i : m) cin >> i.F >> i.S;
    sort(all(m), [](pii a, pii b) { return a.S < b.S; });
    int now_e = 0, ans = 0;
    for (pii i : m) {
        if (i.F >= now_e) ans++, now_e = i.S;
    }
    cout << ans << '\n';
    return 0;
}