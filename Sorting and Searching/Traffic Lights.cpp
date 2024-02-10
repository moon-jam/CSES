#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define F first
#define S second
#define vi vector<int>
#define vii vector<int, int>
#define si set<int>
#define mii map<int, int>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define rev(i, a, b) for (int i = a; i >= b; i--)
#define tomax(a, b) (a) = max((a), (b))
#define tomin(a, b) (a) = min((a), (b))
#define pob pop_back
#define pb push_back
#define eb emplace_back
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sp << " " <<
#define ios ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

signed main() {
    ios;
    int x, n;
    cin >> x >> n;
    vi l(n);
    for(int &i : l) cin >> i;
    si st;
    mii len;
    len[l[0]]++, len[x-l[0]]++, st.insert(l[0]);
    cout << (*len.rbegin()).F << ' ';
    l.erase(l.begin());
    for(int i : l){
        auto up = st.lower_bound(i);
        if(up == st.begin()) {
            len[*up]--, len[*up-i]++, len[i]++, st.insert(i);
        }
        else{
            auto down = prev(up);
            if(up == st.end()) {
                len[x-*down]--, len[i-*down]++, len[x-i]++, st.insert(i);
            }else len[*up-*down]--, len[i-*down]++, len[*up-i]++, st.insert(i);
        }
        // for(auto i : len) cout << i.F << ' ' << i.S << '\n';
        while(((*len.rbegin()).S)==0)  len.erase(prev(len.end()));
        cout << (*len.rbegin()).F << ' ';
    }
    return 0;
}