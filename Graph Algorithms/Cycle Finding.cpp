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
    int n, m, nc = 0;
    cin >> n >> m;
    vii dis(n+1);
    vector<tuple<int, int, int> > g(m);
    for(auto &[a, b, c] : g) cin >> a >> b >> c;
    rep(i, 1, n){
        nc = 0;
        for(auto [a, b, c] : g){
            if(dis[b].F > dis[a].F+c){
                dis[b].F = dis[a].F + c;
                dis[b].S = a;
                nc = a;
            }
        }
    }

    if (nc) {
        cout << "YES\n";
        rep(i, 1, n) nc = dis[nc].S;
        cout << nc;
        vi ans;
        ans.eb(nc);
        for(int cur = dis[nc].S; cur != nc; cur = dis[cur].S) ans.eb(cur);
        reverse(all(ans));
        for(int i : ans) cout sp i;
    } else {
        cout << "NO\n";
    }
    return 0;
}