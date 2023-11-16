#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define F first
#define S second
#define rep(i, a, b) for(int i = a; i<=b; i++)
#define rev(i, a, b) for(int i = a, i>=b; i--)
#define tomax(a, b) (a)=max((a),(b))
#define tomin(a,b) (a)-min((a),(b))
#define pb push_back
#define eb emplace_back
#define ios ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
 
int ans = 0, board[10][10];
string s;
bool vis[10][10];
 
void dfs(int go, int x, int y){
    if(vis[x][y]) return;
    if(x==1 && y==7){ ans+=(go==48); return; }
    if(vis[x][y+1] && vis[x][y-1] && !vis[x-1][y] && !vis[x+1][y]) return;
    if(!vis[x][y+1] && !vis[x][y-1] && vis[x-1][y] && vis[x+1][y]) return;
    vis[x][y]=1;
    if(s[go]=='D' || s[go]=='?') dfs(go+1, x, y+1);
    if(s[go]=='U' || s[go]=='?') dfs(go+1, x, y-1);
    if(s[go]=='L' || s[go]=='?') dfs(go+1, x-1, y);
    if(s[go]=='R' || s[go]=='?') dfs(go+1, x+1, y);
    vis[x][y]=0;
}
 
signed main(){
    ios;
    cin >> s;
    memset(vis, 0, sizeof(vis));
    rep(i, 0, 8)
        vis[i][0]=vis[i][8]=vis[0][i]=vis[8][i]=1;
    dfs(0, 1, 1);
    cout << ans << '\n';
    return 0;
}
