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

int n, q;
int ch[200005][31]; //[i][j] -> 2^j th child of i

void build(){
    rep(i, 1, 30)
        rep(j, 1, n)
            ch[j][i] = ch[ch[j][i-1]][i-1];
}

int query(int x, int k){
    for(int i = 0;k!=0; k>>=1, i++)
        if(k & 1)
            x = ch[x][i];
    return x;
}

signed main() {
    ios;
    cin >> n >> q;
    rep(i, 1, n) cin >> ch[i][0];
    build();
    while(q--){
        int x, k;
        cin >> x >> k;
        cout << query(x, k) << '\n';
    }
    return 0;
}