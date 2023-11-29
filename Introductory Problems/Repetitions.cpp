#include <bits/stdc++.h>
#define int long long
#define eb emplace_back
#define pb push_back
#define tomax(a, b) ((a) = max(a, b))
#define tomin(a, b) ((a) = min(a, b))
using namespace std;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    string in;
    cin >> in;
    int ans = 1;
    vector<char> rep;
    rep.eb(in[0]);
    for (int i = 1; in[i]; i++) {
        if (in[i] != rep.back()) tomax(ans, (int)rep.size()), rep.clear();
        rep.eb(in[i]);
    }
    cout << tomax(ans, (int)rep.size()) << '\n';
    return 0;
}
