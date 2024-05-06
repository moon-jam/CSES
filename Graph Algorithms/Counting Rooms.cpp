#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define F first
#define S second
#define rep(i,a,b) for(int i = a; i<=b; i++)
#define rev(i,a,b) for(int i = a; i>=b; i--)
#define tomax(a,b) (a)=max(a,b)
#define tomin(a,b) (a)=min(a,b)
#define pb push_back
#define eb emplace_back
#define ios ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int n, m, room=0;
bool is_floor[1003][1003];

void dfs(int i, int j){
    if(!is_floor[i][j]) return;
    is_floor[i][j]=0;
    dfs(i+1,j), dfs(i-1,j), dfs(i,j+1), dfs(i,j-1);
}

signed main(){
    ios;
    cin >> n >> m;
    char tmp;
    memset(is_floor, 0, sizeof(is_floor));
    rep(i, 1, n)
        rep(j, 1, m)
            cin>>tmp, is_floor[i][j]=(tmp=='.');
    rep(i, 1, n)
        rep(j, 1, m)
            if(is_floor[i][j])
                room++, dfs(i, j);
    cout << room << '\n';
    return 0;
}