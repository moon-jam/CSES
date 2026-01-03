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

int n;
vi g[200005];
int max_ch[200005], max_ch_sz[200005];

int dfs(int rt, int par){
    int sz = 1;
    for(int i : g[rt]){
        if(i == par) continue;
        int ch = dfs(i, rt);
        sz += ch;
        if(ch > max_ch_sz[rt])
            max_ch[rt] = i, max_ch_sz[rt] = ch;
    }
    return sz;
}

signed main() {
    ios;
    cin >> n;
    rep(i, 1, n-1){
        int a, b;
        cin >> a >> b;
        g[a].eb(b), g[b].eb(a);
    }
    dfs(1, 0);
    int ans = 1, big_ch = 1;
    while(big_ch){
        big_ch = 0;
        if(max_ch_sz[ans]>n/2)
            ans = max_ch[ans], big_ch=ans;
    }
    cout << ans << '\n';
    return 0;
}