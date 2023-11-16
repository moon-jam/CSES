#include <bits/stdc++.h>
#define ios ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define pii pair<int, int>
#define int long long
#define rep(i, a, b) for(int i = a; i<=b; i++ )
#define rev(i, a, b) for(int i = a; i>=b; i-- )
#define tomax(a, b) (a)=max((a), (b))
#define tomin(a, b) (a)=min((a), (b))
#define pb push_back
#define eb emplace_back
using namespace std;

signed main(){
    ios
    int t;
    cin >> t;
    while(t--){
        int a, b;
        cin >> a >>b;
        if(2*a-b>=0 && 2*b-a>=0 && (2*a-b)%3==0 && (2*b-a)%3==0)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}