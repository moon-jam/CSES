#include <bits/stdc++.h>
#define int long long 
#define pii pair<int, int>
#define F first 
#define S second
#define rep(i, a, b) for(int i = a; i<=b; i++)
#define rev(i, a, b) for(int i = a; i>=b; i--)
#define tomax(a,b) (a)=max((a), (b))
#define tomin(a,b) (a)=min((a), (b))
#define pb push_back
#define eb emplace_back
#define ios ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

vector<pii> ans;

void move(int num, int from, int to){
    int use = 6-from-to;
    if(num == 1) ans.eb(from,to);
    else move(num-1,from,use), move(1,from,to), move(num-1,use,to);
}

signed main(){
    ios;
    int n;
    cin >> n;
    move(n, 1, 3);
    cout << ans.size() << '\n';
    for(pii i : ans)
        cout << i.F << ' ' << i.S << '\n';
    return 0;
}
