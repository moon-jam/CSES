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
    int n, k, ans = 0;
    cin >> n >> k;
    vi arr(n);
    for(int &i : arr) cin >> i;

    int l = 0, r=1;
    mii m;
    m[arr[0]]++;
    while(l<=n){
        while(r<=n && m.size()<=k) m[arr[r++]]++;
        ans+=r-1-l;
        m[arr[l]]--;
        if(m[arr[l]]==0) m.erase(arr[l]);
        l++;
    }cout << ans << '\n';
    return 0;
}