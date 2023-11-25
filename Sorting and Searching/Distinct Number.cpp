#include <bits/stdc++.h>
#define int long long
#define pii pair<int ,int>
#define F first
#define S second
#define rep(i, a, b) for(int i = a; i<=b; i++)
#define rev(i, a, b) for(int i = a; i>=b; i--)
#define tomax(a, b) (a)=max((a),(b))
#define tomin(a, b) (a)=min((a),(b))
#define pb push_back
#define eb emplace_back
#define ios ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

signed main(){
    ios;
    int n;
    set<int> x;
    cin >> n;
    int tmp;
    rep(i, 1, n) cin >> tmp, x.insert(tmp);
    cout << x.size() << '\n';
    return 0;
}