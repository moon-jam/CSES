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
    vii num(n);
    rep(i, 1, n) cin >> num[i - 1].F, num[i - 1].S = i;
    sort(all(num));
    unordered_map<int, pii> pos;
    rep(i, 0, n - 1) {
        rep(j, i + 1, n - 1) {
            auto pt = pos.find(x - num[i].F - num[j].F);
            if (pt != pos.end()) {
                cout << num[i].S sp num[j].S sp pt->S.F sp pt->S.S << '\n';
                return 0;
            }
        }
        rep(j, 0, i - 1)
            pos.insert({num[i].F + num[j].F, {num[i].S, num[j].S}});
    }
    cout << "IMPOSSIBLE\n";
    return 0;
}