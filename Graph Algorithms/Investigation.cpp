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

int mod = 1e9+7;

int n, m;
vii g[100005];
int dis[100005];
int way[100005];
int max_route[100005];
int min_route[100005];
bool vis[100005];

signed main() {
    ios;
    cin >> n >> m;
    rep(i, 1, m){
        int a, b, c;
        cin >> a >> b >> c;
        g[a].eb(b,c);
    }
    fill(dis, dis+n+1, 1e18);
    fill(min_route, min_route+n+1, 1e18);
    priority_queue<pii, vii, greater<pii>> pq;
    pq.push({0, 1}), dis[1]=0, way[1]=1, max_route[1]=min_route[1]=0;
    while(!pq.empty()){
        pii cur = pq.top();
        pq.pop();
        if(vis[cur.S]) continue;
        vis[cur.S]=1;
        for(pii i: g[cur.S]){
            if(dis[i.F] == cur.F+i.S){
                (way[i.F] += way[cur.S]) %= mod;
                tomax(max_route[i.F], max_route[cur.S]+1);
                tomin(min_route[i.F], min_route[cur.S]+1);
            }
            if(dis[i.F] > cur.F+i.S){
                dis[i.F] = cur.F+i.S;
                way[i.F] = way[cur.S];
                max_route[i.F] = max_route[cur.S]+1;
                min_route[i.F] = min_route[cur.S]+1;
                pq.push({dis[i.F], i.F});
            }
        }
    }
    cout << dis[n] sp way[n] sp min_route[n] sp max_route[n] << '\n';
    return 0;
}