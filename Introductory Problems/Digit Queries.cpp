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
#define take(num, pos) ((pos==1) ? (num%10) : (num%pow[pos+1])/pow[pos])
using namespace std;
 
signed main(){
    ios;
    int q, u[20], pow[20];
    u[0]=0;
    for(int i = 1, add=1; i<=1e18; add++, i*=10)
        u[add] = u[add-1]+(i*10-i)*add, pow[add]=i;
    cin >> q;
    while(q--){
        int cmd;
        cin >> cmd;
        int pos = 0;
        while(cmd>u[pos]) pos++;
        int num = cmd<10 ? cmd : ((cmd-u[pos-1]-1)/(pos) + pow[pos]);
        // cout << num << ' ' << pos << ' ' << u[pos-1] << ' ' << (pos-((cmd-u[pos-1]-1)%pos)) << '\n';
        cout << (cmd<10? cmd : (take(num, pos-((cmd-u[pos-1]-1)%pos))) ) << '\n';
    }
    return 0;
}