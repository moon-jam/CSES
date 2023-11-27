#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define F first
#define S second
#define rep(i, a, b) for(int i = a; i<=b; ++i)
#define rev(i, a, b) for(int i = a; i>=b; --i)
#define tomax(a, b) (a)=max((a),(b))
#define tomin(a, b) (a)=min((a),(b))
#define all(a) a.begin(), a.end()
#define pob pop_back
#define pb push_back
#define eb emplace_back
#define ios ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int n, m;
pii a, b;
bool find_path = false;
bool graph[1003][1003];
queue<pii> q;
vector<char> path;
int dir[1003][1003];

signed main(){
    ios;
    memset(graph, 0, sizeof(graph));
    cin >> n >> m;
    char tmp;
    rep(i, 1, n)
        rep(j, 1, m)
            cin >> tmp, graph[j][i]=(tmp!='#'&&tmp!='A'),
            a = (tmp=='A' ? make_pair(j,i) : a),
            b = (tmp=='B' ? make_pair(j,i) : b);
    q.push(a);
    while(q.size()){
        int x = q.front().F, y = q.front().S; q.pop();
        if(x==b.F && y==b.S){ find_path=true; break;}
        if(graph[x-1][y]) dir[x-1][y]='L', graph[x-1][y]=0, q.push({x-1, y});
        if(graph[x+1][y]) dir[x+1][y]='R', graph[x+1][y]=0, q.push({x+1, y});
        if(graph[x][y-1]) dir[x][y-1]='U', graph[x][y-1]=0, q.push({x, y-1});
        if(graph[x][y+1]) dir[x][y+1]='D', graph[x][y+1]=0, q.push({x, y+1});
    }
    if(!find_path){cout << "NO\n"; return 0;}
    while(a!=b){
        path.pb(dir[b.F][b.S]);
        if(dir[b.F][b.S]=='L') b={b.F+1, b.S};
        else if(dir[b.F][b.S]=='R') b={b.F-1, b.S};
        else if(dir[b.F][b.S]=='U') b={b.F, b.S+1};
        else if(dir[b.F][b.S]=='D') b={b.F, b.S-1};
    }reverse(all(path));
    cout << "YES\n" << path.size() << '\n';
    for(char i : path) cout << i;
    cout << '\n';
    return 0;
}