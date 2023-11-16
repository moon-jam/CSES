#include<bits/stdc++.h>
#define int long long
#define eb emplace_back
#define pb push_back
#define tomax(a, b) ((a)=max(a,b))
#define tomin(a, b) ((a)=min(a,b))
using namespace std;

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int y, x;
        cin >> y >> x;
        if(x >= y) 
            if(x%2) cout << x*x-(y-1) << '\n';
            else cout << (x-1)*(x-1)+(y) << '\n';
        else
            if(y%2==0) cout << y*y-(x-1) << '\n';
            else cout << (y-1)*(y-1)+(x) << '\n';
    }
    return 0;
}
