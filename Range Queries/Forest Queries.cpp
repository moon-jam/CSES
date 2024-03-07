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

int pre[1003][1003];

signed main() {
    ios;
    int n, q;
    char tmp;
    cin >> n >> q;
    rep(i, 1, n) rep(j, 1, n) cin >> tmp,
        pre[i][j] =
            (tmp == '*') + pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1];
    while(q--){
        int x1, x2, y1, y2;
        cin >> y1 >> x1 >> y2 >> x2;
        if(x2<x1) swap(x1, x2);
        if(y2<y1) swap(y1, y2);
        cout << pre[y2][x2] + pre[y1-1][x1-1] - pre[y2][x1-1] - pre[y1-1][x2] << '\n';
    }
    return 0;
}