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
    int n, x, divide = -1;
    map<int, int> arr;
    cin >> n >> x;
    if (x % 2 == 0) divide = x / 2;
    rep(i, 1, n) {
        int a;
        cin >> a, arr.insert({a, i});
        if (a == x / 2 && divide != -1) {
            if (divide != x / 2) {
                cout << divide - x / 2 sp i << '\n';
                return 0;
            }
            divide += i;
        }
    }
    bool ok = false;
    for (pii i : arr) {
        if (i.F==x-i.F) continue;
        if (arr.count(x - i.F)) {
            cout << i.S sp arr[x - i.F] << '\n';
            ok = true;
            break;
        }
    }
    if (!ok) cout << "IMPOSSIBLE\n";
    return 0;
}