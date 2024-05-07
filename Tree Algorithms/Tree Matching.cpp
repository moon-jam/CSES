#include <bits/stdc++.h>
using namespace std;
/* TYPES  */
#define int long long
#define pii match<int, int>
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

int n, ans;
vi g[200005];
bool match[200005];
//假設子孫的樹已經是最佳答案（最大配對），那讓眾多子孫選擇是否與父母一對，因為父母一定只能成全一對子孫，所以不管選誰都不會影響答案，所以在父母這層答案是最大

void dfs(int rt, int par){
    for(int i : g[rt]){
        if(i==par) continue;
        dfs(i, rt);
        if(!match[rt] && !match[i]) match[rt]=match[i]=1, ans++;
    }
}

signed main() {
    ios;
    cin >> n;
    
    rep(i, 2, n){
        int a, b;
        cin >> a >> b;
        g[a].eb(b), g[b].eb(a);
    }
    dfs(1, 0);
    cout << ans << '\n';
    return 0;
}