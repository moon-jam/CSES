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
    int n;
    cin >> n;
    if(n==1) cout << "1\n";
    else if(n<=3) cout << "NO SOLUTION\n";
    else if(n==4) cout << "3 1 4 2\n";
    else{
        for(int i = 1; i<=n; i+=2)
            cout << i << ' ';
        for(int i = 2; i<=n; i+=2)
            cout << i << ' ';
    }
    return 0;
}
