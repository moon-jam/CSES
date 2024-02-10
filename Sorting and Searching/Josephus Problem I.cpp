#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pii pair<int, int>
#define F first
#define S second
#define vi vector<int>
#define vii vector<pii>
#define si set<int>
#define mii map<int, int>

#define tomax(a,b) (a)=max((a),(b))
#define tomin(a,b) (A)=min((a),(b))
#define rep(i, a, b) for(int i = a; i<=b; i++)
#define rev(i, a, b) for(int i = a; i>=b; i++)
#define pob pop_back
#define pb push_back
#define eb emplace_back
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define ios ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

signed main(){
    // ios;
    int n; 
    cin >> n;
    list<int> arr;
    rep(i, 1, n) arr.push_back(i);
    auto idx = next(arr.begin());
    while(!arr.empty()){
        cout << *idx << ' ';
        if(arr.size()==1) break;
        else if(arr.size()==2) arr.erase(idx), idx=arr.begin(); 
        else if(idx==prev(arr.end())) arr.erase(idx), idx=next(arr.begin());
        else if(idx==prev(arr.end(),2)) arr.erase(idx), idx=arr.begin();
        else idx = next(idx, 2), arr.erase(prev(idx, 2));
    }
    return 0;
}