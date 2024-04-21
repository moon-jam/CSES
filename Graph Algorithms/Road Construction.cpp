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

int n, m, maxB;
int boss[100005];
int sizeB[100005];

int find_boss(int ch) {
    if (ch == boss[ch]) return ch;
    return boss[ch] = find_boss(boss[ch]);
}

signed main() {
    ios;
    cin >> n >> m;
    rep(i, 1, n) boss[i] = i, sizeB[i] = 1;
    while (m--) {
        int a, b;
        cin >> a >> b;
        if (find_boss(a) != find_boss(b))
            n--, tomax(maxB, sizeB[find_boss(b)] += sizeB[find_boss(a)]), boss[find_boss(a)] = boss[find_boss(b)];
        cout << n sp maxB << '\n';
    }
    return 0;
}