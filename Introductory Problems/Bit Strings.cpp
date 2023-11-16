#include<bits/stdc++.h>
#define int long long
#define eb emplace_back
#define pb push_back
#define tomax(a, b) ((a)=max(a,b))
#define tomin(a, b) ((a)=min(a,b))
#define rep(i, a, b) for(int i = (a); i<=(b); ++i)
#define rev(i, a, b) for(int i = (a); i>=(b); --i)
using namespace std;

const int mod = 1E9 + 7;

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, ans = 1;
    cin >> n;
    rep(i, 1, n) ans = (ans<<1) % mod;
    cout << ans % mod << '\n';
    return 0;
}
