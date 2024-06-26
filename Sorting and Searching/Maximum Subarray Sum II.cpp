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
    int n, a, b, tmp, ans = -1e18;
    cin >> n >> a >> b;
    vi pre(n + 1);
    pre[0] = 0;
    rep(i, 1, n) cin >> tmp, pre[i] = pre[i - 1] + tmp;
    multiset<int> ms;
    rep(i, a, n) {
        if (i > b) ms.erase(ms.find(pre[i - b - 1]));
        ms.insert(pre[i-a]);
        tomax(ans, pre[i] - *ms.begin());
    }
    cout << ans << '\n';
    return 0;
}