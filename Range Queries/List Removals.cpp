#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;

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
    int n, tmp;
    tree<pii, null_type, less<pii>, rb_tree_tag,
         tree_order_statistics_node_update>
        r;
    cin >> n;
    rep(i, 1, n) cin >> tmp, r.insert({i, tmp});
    rep(i, 1, n) {
        cin >> tmp;
        auto it = r.find_by_order(tmp - 1);
        cout << it->S << ' ';
        r.erase(it);
    }
    return 0;
}