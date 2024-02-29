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
    int n, x, ans = 0;
    cin >> n >> x;
    vi sum(n+1);
    map<int, vi> ms;
    sum[0]=0;
    ms[0].eb(0);
    rep(i, 1, n) cin >> sum[i], sum[i]+=sum[i-1], ms[sum[i]].eb(i);
    rep(i, 1, n){
        if(!ms[sum[i]-x].empty() && *ms[sum[i]-x].begin()<i) ans+=(lower_bound(all(ms[sum[i]-x]),i)-ms[sum[i]-x].begin());
    }cout << ans << '\n';
    return 0;
}