#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int x;
    cin >> x;
    cout << x << ' ';
    while(x!=1){
        if(x%2) x=x*3+1;
        else x=x/2;
        cout << x << ' ';
    }
    return 0;
}
