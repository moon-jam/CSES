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
    cout << "0\n";
    for(int i = 2; i<=n; i++){
        // all possible ways to place 2 knights on a board of size i*i
        // i*i + i*i-1 + i*i-2 + ... + 1 = (i*i)*(i*i+1)/2
        // all possible ways that 2 knights attack each other 
        cout << ((i*i)*(i*i-1))/2 - 2*(2*(i-1)*(i-2)) << '\n';
    }
    return 0;
}
