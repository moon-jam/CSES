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

int bit[200005];

void update(int n, int x, int chg){
    for(;x<=n; x+=(x&-x)) bit[x]+=chg;
}

int query(int x){
    int ans = 0;
    for(;x>=1; x-=(x&-x)) ans+=bit[x];
    return ans;
}

signed main() {
    // ios;
    int n, a, b;
    cin >> n;
    vi con(n), coned(n);
    mii bRank;
    vector<pair<pii, int>> range;

    rep(i, 0, n - 1) cin >> a >> b, range.pb({{a, b}, i}), bRank[b]=1;

    int nn=1;
    for(auto &i : bRank) i.S=nn++;
    nn--;

    sort(all(range), [](pair<pii, int> a, pair<pii, int> b) {
        if (a.F.F == b.F.F) return a.F.S > b.F.S;
        return a.F.F < b.F.F;
    });

    int cnt = 0;
    for (auto i : range) {
        coned[i.S] = cnt-query(bRank[i.F.S]-1);
        update(nn, bRank[i.F.S], 1);
        cnt++;
    }

    reverse(all(range));
    memset(bit, 0, sizeof(bit));
    for (auto i : range) {
        con[i.S] = query(bRank[i.F.S]);
        update(nn, bRank[i.F.S], 1);
        cnt++;
    }

    for (int i : con) cout << i << ' ';
    cout << '\n';
    for (int i : coned) cout << i << ' ';
    return 0;
}
