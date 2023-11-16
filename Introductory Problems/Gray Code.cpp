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
    int n;
    cin >> n;
    rep(i, 0, (1<<n)-1){
        cout << (i>>(n-1));
        rev(j, n-2, 0)
            cout << (((i>>j)&1) ^ ((i>>(j+1))&1));
        cout << '\n';
    }
    return 0;
}

/*
1:
0
1

2:
00
01
11
10

3:
000
001
011
010
110
111
101
100

n:
0 (n-1)_0
0 (n-1)_1
0 (n-1)_2
.
.
0 (n-1)_n-1
1 (n-1)_n-1
1 (n-1)_n-2
1 (n-1)_n-3
.
.
1 (n-1)_0
*/