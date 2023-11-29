#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define F first
#define S second
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define rev(i, a, b) for (int i = a; i >= b; --i)
#define tomax(a, b) (a) = max((a), (b))
#define tomin(a, b) (a) = min((a), (b))
#define all(a) a.begin(), a.end()
#define pob pop_back
#define pb push_back
#define eb emplace_back
#define ios ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int n, m, tmp1, tmp2;
int last_cpu[100005];
vector<int> E[100005];
vector<int> ans;

signed main() {
    ios;
    // BFS
    fill(last_cpu, last_cpu+100005, INT_MAX);
    cin >> n >> m;
    rep(i, 1, m) cin >> tmp1 >> tmp2, E[tmp1].eb(tmp2), E[tmp2].eb(tmp1);
    queue<int> q;
    q.push(1); last_cpu[1]=1;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(int x : E[cur])
            if(last_cpu[x]==INT_MAX) q.push(x), last_cpu[x]=cur;
    }
    if(last_cpu[n]!=INT_MAX){
        while(n!=1){
            ans.pb(n);
            n=last_cpu[n];
        }cout << ans.size()+1 << '\n';
        reverse(all(ans));
        cout << 1 << ' ';
        for(int x : ans) cout << x << ' ';
    }else{
        cout << "IMPOSSIBLE\n";
    }
    return 0;
}