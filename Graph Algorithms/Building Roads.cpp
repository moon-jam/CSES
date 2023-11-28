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

int bose[100005];

int fb(int ch){
    if(ch==bose[ch]) return ch;
    return bose[ch]=fb(bose[ch]);
}

signed main(){
    ios;
    // minimum spanning tree
    int n, m, connect=0;
    cin >> n >> m;
    vector<pii> E(m);
    for(pii &x : E) cin >> x.F >> x.S;
    rep(i, 1, n) bose[i]=i;
    for(pii path : E){
        if(connect==0 || fb(path.F) != fb(path.S))
            bose[fb(path.F)]=bose[fb(path.S)], connect++;
    }cout << n-1-connect << '\n';
    rep(i, 2, n){
        if(fb(i-1)!=fb(i))
            bose[fb(i-1)]=bose[fb(i)], cout << i-1 << ' ' << i << '\n';
    }
    return 0;
}
