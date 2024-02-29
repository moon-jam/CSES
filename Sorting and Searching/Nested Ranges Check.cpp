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
    int n, a, b;
    cin >> n;
    vector<bool> con(n), coned(n);
    vector<pair<pii, int>> ran;

    rep(i, 0, n - 1) cin >> a >> b, ran.pb({{a, b}, i});

    sort(all(ran), [](pair<pii, int> a, pair<pii, int> b) {
        if (a.F.F == b.F.F) return a.F.S > b.F.S;
        return a.F.F < b.F.F;
    });
    int max_r = 0;
    for (auto i : ran) {
        if (i.F.S > max_r)
            max_r = i.F.S, coned[i.S] = 0;
        else
            coned[i.S] = 1;
    }

    reverse(all(ran));
    int min_r = 2e9;
    for (auto i : ran) {
        if (i.F.S < min_r)
            min_r = i.F.S, con[i.S] = 0;
        else
            con[i.S] = 1;
    }

    for (bool i : con) cout << i << ' ';
    cout << '\n';
    for (bool i : coned) cout << i << ' ';
    return 0;
}
