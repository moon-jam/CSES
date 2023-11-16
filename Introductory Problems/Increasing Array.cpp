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
    int ans = 0, last;
    cin >> last;
    for(int i = 1, tmp; i<n; i++)
        cin >> tmp, ans+=(last-tmp)*(tmp<last), tomax(last, tmp);
    cout << ans << '\n';
    return 0;
}
