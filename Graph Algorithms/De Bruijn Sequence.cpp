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
vi g[100005], ans;

void dfs(int rt){
    while(!g[rt].empty()){
        int cur = g[rt].back();
        g[rt].pob();
        dfs(cur);
        ans.eb(rt&1);
    }
}

signed main() {
    ios;
    cin >> n;
    rev(i, (1<<(n-1))-1, 0){
        int nxt = (i<<1) & ((1<<(n-1))-1);
        g[i].eb(nxt);
        g[i].eb(nxt+1);
    }
    dfs(0);
    reverse(all(ans));
    rep(i,1,n-1) cout << 0;
    if(n==1) cout << "01";
    else for(int i : ans) cout << i;
    return 0;
}