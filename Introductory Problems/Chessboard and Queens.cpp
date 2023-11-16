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
 
bool go[10][10];
int ans = 0;
 
bool check(int board[10]){
    bool ok = true;
    rep(i, 1, 8){
        if(!go[i][board[i]]) ok = false;
        rep(j, 1, 8)
            if(i!=j)
                ok = (ok && (board[j]!=board[i]+(j-i)) && (board[j]!=board[i]-(j-i)));
    }
    return ok;
}
 
void test(int pos, int board[10], bool dont[10]){
    if(pos == 9){ans+=check(board); return;}
    rep(i, 1, 8)
        if(!dont[i])
            board[pos]=i, dont[i]=1, test(pos+1, board, dont), dont[i]=0;
}
 
signed main(){
    ios;
    char cmd;
    rep(i,1,8)
        rep(j, 1, 8)
            cin >> cmd, go[j][i]=(cmd=='.');
    int blank[10]; bool blank2[10];
    memset(blank2, 0, sizeof(blank2));
    test(1, blank, blank2);
    cout << ans << '\n';
    return 0;
}