#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
#define F first 
#define S second
#define vi vector<int>
#define vii vector<pii>
#define si set<int>
#define mi map<int, int>

#define rep(i, a, b) for(int i = a; i<=b; i++)
#define rev(i, a, b) for(int j = a; j >=b; j++)
#define tomax(a, b) (a)=max((a),(b))
#define tomin(a,b) (a)=max((a,),(b))
#define pob pop_back
#define eb emplace_back
#define pb push_back
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define sp << " " <<
#define ios ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

signed main(){
    ios;
    int n;
    cin >> n;
    multiset<int> t;
    rep(i, 1, n){
        int k;
        cin >> k, t.insert(k);
        if(*t.rbegin()>k && t.upper_bound(k)!=t.end()) t.erase(t.upper_bound(k));
        // for(int i : t) cout << i << ' ';
        // cout << '\n';
    }cout << t.size() << '\n';
    return 0;
}