#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define sp << " " <<
#define ios ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

signed main() {
    ios;
    int n, x;
    cin >> n >> x;
    vector<pair<int, int>> num(n);
    rep(i, 1, n) cin >> num[i - 1].F, num[i - 1].S = i;
    sort(num.begin(), num.end());
    rep(i, 0, n-1) {
        int tar = x - num[i].F;
        int l = 0, r = n - 1;
        while (r > l) {
            if (l != i && r != i && num[l].F + num[r].F == tar) {
                cout << num[l].S sp num[r].S sp num[i].S << '\n';
                return 0;
            }
            if (num[l].F + num[r].F > tar)
                r--;
            else
                l++;
        }
    }
    cout << "IMPOSSIBLE\n";

    return 0;
}