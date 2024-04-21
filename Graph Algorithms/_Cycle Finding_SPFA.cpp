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
 
vii g[3003];
pii dis[3003];
int n, m, a, b, c;
int nc = 0;
vi ans;
int vis[3003];
bool inq[3003];
 
signed main() {
    ios;
    cin >> n >> m;
    rep(i, 1, m) cin >> a >> b >> c, g[a].eb(b, c);
    
    queue<int> q;
    rep(i, 1, n) q.push(i), inq[i] = 1;
    while(!q.empty() && !nc){
        int cur = q.front();
        q.pop();
        inq[cur] = 0;
        for(pii i : g[cur]){
            if(dis[i.F].F > dis[cur].F + i.S){
                dis[i.F].F = dis[cur].F + i.S;
                dis[i.F].S = cur;
                vis[i.F]++;
                if(vis[i.F]>=n) {nc=i.F; break;}
                if(!inq[i.F]) q.push(i.F), inq[i.F] = 1;
            }
        }
    }
    
    if (nc) {
        cout << "YES\n";
        rep(i, 1, n) nc = dis[nc].S;
        cout << nc;
        vi ans;
        ans.eb(nc);
        for(int cur = dis[nc].S; cur != nc; cur = dis[cur].S) ans.eb(cur);
        reverse(all(ans));
        for(int i : ans) cout sp i;
    } else {
        cout << "NO\n";
    }
    return 0;
}