#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define F first
#define S second
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define rev(i, a, b) for (int i = a; i >= b; --i)
#define tomax(a, b) (a) = max((a), (b))
#define tomin(a, b) (a) = min((a), (b))
#define all(a) a.begin(), a.end()
#define pob pop_back
#define pb push_back
#define eb emplace_back
#define ios ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

signed main() {
    // ios;
    int n, m, tmp;
    map<int, int> ticket;
    cin >> n >> m;
    rep(i, 1, n) cin >> tmp, ticket[tmp]++;
    rep(i, 1, m){
        cin >> tmp;
        auto it_bigger_price = ticket.upper_bound(tmp);
        if(it_bigger_price == ticket.begin()) cout << -1 << '\n';
        else{
            auto it_price = prev(it_bigger_price);
            ticket[(*it_price).F]--, cout << (*it_price).F << '\n';
            if(ticket[(*it_price).F]==0) ticket.erase(it_price);
        }
    }
    return 0;
}