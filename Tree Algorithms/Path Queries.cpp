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

struct BIT {
    int n;
    vi bit;
    BIT(int _n) : n(_n), bit(_n+1) {}
    void modify(int pos, int val){
        for(;pos<=n; pos+=pos&(-pos)) bit[pos]+=val;
    }
    int query(int pos){
        int ans = 0;
        for(;pos>0; pos-=pos&(-pos)) ans += bit[pos];
        return ans;
    }
} bit(400005);

int n, q;
int in[200005], out[200005], w[200005];
vi g[200005];

void dfs(int rt, int pa, int &time){
    bit.modify(time, w[rt]);
    in[rt] = time++;
    for(int i : g[rt]) if(pa != i) dfs(i, rt, time);
    bit.modify(time, -w[rt]);
    out[rt] = time++;
}

signed main() {
    ios;
    cin >> n >> q;
    rep(i, 1, n) cin >> w[i];
    rep(i, 1, n-1){
        int a, b;
        cin >> a >> b;
        g[a].eb(b), g[b].eb(a);
    }
    dfs(1, 0, *(new int(1)));
    while(q--){
        int cmd, a, b;
        cin >> cmd >> a;
        if(cmd == 1) cin >> b, bit.modify(in[a], b-w[a]), bit.modify(out[a], w[a]-b), w[a] = b;
        else cout << bit.query(in[a]) << '\n';
    }
    return 0;
}