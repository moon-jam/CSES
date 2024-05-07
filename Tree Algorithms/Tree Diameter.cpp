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

int n, ans;
int d1[200005], d2[200005];
vi g[200005];

void dfs(int rt, int par){
    d1[rt] = 1, d2[rt] = 0;
    for(int i : g[rt]){
        if(i == par) continue;
        dfs(i, rt);
        if(d1[i]+1 > d1[rt]) d2[rt] = d1[rt], d1[rt]=d1[i]+1;
        else if(d1[i]+1 >= d2[rt]) d2[rt]=d1[i]+1;
    }
}

signed main() {
    ios;
    cin >> n;
    rep(i, 2, n){
        int a, b;
        cin >> a >> b;
        g[a].eb(b);
        g[b].eb(a);
    }
    dfs(1, 0);
    cout << d1[1]+d2[1]-2 << '\n';
    return 0;
}