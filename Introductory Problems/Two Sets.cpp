#include<bits/stdc++.h>
#define int long long
#define eb emplace_back
#define pb push_back
#define tomax(a, b) ((a)=max(a,b))
#define tomin(a, b) ((a)=min(a,b))
#define rep(i, a, b) for(int i = (a); i<=(b); ++i)
#define rev(i, a, b) for(int i = (a); i>=(b); --i)
using namespace std;

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    if((n*(n+1)/2) % 2) cout << "NO\n";
    else{
        cout << "YES\n";
        if(n%4 == 0){
            cout << n/2 << '\n';
            rep(i, 1, (n/4)) cout << i << ' ' << n+1-i << ' ';
            cout << '\n' << n/2 << '\n';
            rep(i, (n/4)+1, n/2) cout << i << ' ' << n+1-i << ' ';
        }else{
            cout << n/2 + 1 << '\n';
            rep(i, 1, n/2) cout << i++ << ' ';
            rep(i, n/2+1, n-1) cout << i++ << ' ';
            cout << '\n' << n/2 << '\n';
            rep(i, 2, n/2-1) cout << i++ << ' ';
            rep(i, n/2+2, n) cout << i++ << ' ';
        }
    }
    return 0;
}
