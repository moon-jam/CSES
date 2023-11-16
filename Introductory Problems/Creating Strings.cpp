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

set<string> ans;
string s;
int len;

void select(int pos, string cur, bool used[10]){
    if(pos == len) {ans.insert(cur); return;}
    rep(i, 0, len-1){
        if(!used[i])
            used[i]=1, select(pos+1, cur+s[i], used),used[i] = 0;;
    }
}

signed main(){
    ios;
    cin >> s;
    len = s.size();
    string tmp; bool tmp2[10];
    memset(tmp2, 0, sizeof(tmp2));
    select(0,tmp,tmp2);
    cout << ans.size() << '\n';
    for(string i : ans)
        cout << i << '\n';
    return 0;
}
