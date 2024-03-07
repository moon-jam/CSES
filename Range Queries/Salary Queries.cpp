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

template <class T>
using Tree = tree<T, null_type, less_equal<T>, rb_tree_tag,
                  tree_order_statistics_node_update>;

signed main() {
    ios;
    int n, q;
    Tree<int> tr;
    int arr[200005];
    cin >> n >> q;
    rep(i, 1, n) cin >> arr[i], tr.insert(arr[i]);
    while (q--) {
        char cmd;
        int a, b;
        cin >> cmd >> a >> b;
        if (cmd == '!')
            tr.erase(tr.find_by_order(tr.order_of_key(arr[a]))), tr.insert(b), arr[a]=b;
        else
            cout << tr.order_of_key(b + 1) - tr.order_of_key(a) << '\n';
    }
    return 0;
}