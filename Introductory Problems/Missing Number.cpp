#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    bool arr[200005];
    memset(arr, 0, sizeof(arr));
    for(int i = 0, tmp; i<n-1; i++)
        cin >> tmp, arr[tmp]=1;
    int ans;
    for(int i = 1; i<=n; i++)
        if(!arr[i])
            ans = i;
    cout << ans << '\n';
    return 0;
}
