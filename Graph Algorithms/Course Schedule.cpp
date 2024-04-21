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

int n, m;
vi g[100005];
int deg[100005];

signed main() {
    ios;
    cin >> n >> m;
    rep(i, 1, m){
        int a, b;
        cin >> a >> b;
        deg[b]++;
        g[a].eb(b);
    }
    queue<int> q;
    vi ord;
    int cnt = 0;
    rep(i, 1, n) {
        if(deg[i]==0) q.push(i);
    }
    while(!q.empty()){
        ord.eb(q.front()), q.pop();
        cnt++;
        for(int i : g[ord.back()]){
            deg[i]--;
            if(deg[i]==0)q.push(i);
        }
    }
    if(cnt != n) {
        cout << "IMPOSSIBLE\n";
    } else {
        for(int i : ord) cout << i << ' ';
    }
    return 0;
}