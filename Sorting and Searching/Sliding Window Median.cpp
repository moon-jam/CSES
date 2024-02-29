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
    int n, k, tmp;
    cin >> n >> k;
    vi arr;
    vector<set<pii>::iterator > parr;
    set<pii> sarr;
    rep(i, 0, k - 1) cin >> tmp, parr.eb(sarr.insert({tmp, i}).F), arr.eb(tmp);
    auto p = next(sarr.begin(), (k - 1) / 2);
    cout << p->F << ' ';
    rep(i, k, n-1) {
        cin >> tmp;
        parr.eb((sarr.insert({tmp,i})).F);
        arr.eb(tmp);
        if (arr[i - k] == p->F && tmp < p->F)
            p = prev(p);
        else if (arr[i - k] == p->F && tmp >= p->F)
            p = next(p);
        else if (arr[i - k] > p->F && tmp < p->F)
            p = prev(p);
        else if (arr[i - k] < p->F && tmp >= p->F)
            p = next(p);
        if(p==parr[i-k]) p=next(p);
        sarr.erase(parr[i-k]);
        cout << p->F << ' ';
    }
    return 0;
}